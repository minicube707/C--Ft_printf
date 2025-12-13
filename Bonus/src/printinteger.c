/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:11:22 by marvin            #+#    #+#             */
/*   Updated: 2025/12/13 02:08:14 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printinteger_plus(t_flags *catch_flags, int num)
{
	int	n;

	n = 0;
	if (catch_flags->plus && num >= 0)
		n += write(1, "+", 1);
	return (n);
}

static int	printinteger_skip_begin(t_flags *catch_flags, int max)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i++ < catch_flags->number - max - catch_flags->space
		- catch_flags->plus && !catch_flags->minus && !catch_flags->zeros)
		n += write(1, " ", 1);
	i = 0;
	while (i++ < catch_flags->number - max - catch_flags->space
		- catch_flags->plus && !catch_flags->minus && catch_flags->zeros)
		n += write(1, "0", 1);
	return (n);
}

static int	printinteger_space(t_flags *catch_flags, int num)
{
	int	n;

	n = 0;
	if (catch_flags->space && num >= 0)
		n += write(1, " ", 1);
	if (num < 0)
		n += write(1, "-", 1);
	return (n);
}

int	printinteger(t_flags *catch_flags, int num)
{
	int 	i;
	int		n;
	int		max;
	char	buff[32];
	char	*res;

	ft_bzero(buff, 32);
	res = ft_putnbr(buff, num);
	max = get_max(catch_flags, res);
	n = 0;
	n += printinteger_space(catch_flags, num);
	n += printinteger_skip_begin(catch_flags, max);
	n += printinteger_plus(catch_flags, num);
	n += printinteger_dot(catch_flags, res);
	i = 0;
	if (num < 0)
		i = 1;	
	while (res[i] != '\0')
	{
		n += write(1, &res[i], 1);
		i++;
	}
	n += printinteger_minus(catch_flags, max);
	return (n);
}
