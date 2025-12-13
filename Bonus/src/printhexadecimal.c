/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexadecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:00:08 by marvin            #+#    #+#             */
/*   Updated: 2025/12/13 02:31:11 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printhexadecimal_minus(t_flags *catch_flags, int max)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < catch_flags->number - max - catch_flags->plus - (catch_flags->sharp * 2)
		&& catch_flags->minus)
		n += write(1, " ", 1);
	return (n);
}

static int	printhexadecimal_dot(t_flags *catch_flags, char *res)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < catch_flags->dot_val - ft_strlen(res))
		n += write(1, "0", 1);
	return (n);
}

static int	printhexadecimal_skip_begin(t_flags *catch_flags, int max)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i++ < catch_flags->number - max - catch_flags->space
		- catch_flags->plus - (catch_flags->sharp * 2) && !catch_flags->minus && !catch_flags->zeros)
		n += write(1, " ", 1);
	i = 0;
	while (i++ < catch_flags->number - max - catch_flags->space
		- catch_flags->plus - (catch_flags->sharp * 2) && !catch_flags->minus && catch_flags->zeros)
		n += write(1, "0", 1);
	return (n);
}

int	printhexadecimal(t_flags *catch_flags, unsigned int num, int mode)
{
	int		n;
	int		max;
	char	buff[32];
	char	*res;

	ft_bzero(buff, 32);
	res = ft_puthexnbr(buff, num, mode);
	max = get_max(catch_flags, res);
	n = 0;
	n += printhexadecimal_skip_begin(catch_flags, max);
	n += printhexadecimal_dot(catch_flags, res);
	if (catch_flags->sharp && num != 0)
	{
		if (mode)
			n += write(1, "0X", 2);
		else
			n += write(1, "0x", 2);
	}
	n += write(1, res, ft_strlen(res));
	n += printhexadecimal_minus(catch_flags, max);
	return (n);
}
