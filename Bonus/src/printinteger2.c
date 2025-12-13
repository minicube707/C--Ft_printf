/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printinteger2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:54:57 by fmotte            #+#    #+#             */
/*   Updated: 2025/12/13 01:51:57 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putnbr(char *string, int nb)
{
	if (nb == -2147483648)
	{
		ft_strlcpy(string, "-2147483648", 12);
		return (string);
	}
	if (nb < 0)
	{
		string[0] = '-';
		return (ft_putnbr(string, -nb));
	}
	if (nb > 9)
	{
		string = ft_putnbr(string, nb / 10);
		ft_putnbr(string, nb % 10);
	}
	else
		string[ft_strlen(string)] = nb + 48;
	return (string);
}

int	printinteger_minus(t_flags *catch_flags, int max)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < catch_flags->number - max - catch_flags->plus
		&& catch_flags->minus)
		n += write(1, " ", 1);
	return (n);
}

int	printinteger_dot(t_flags *catch_flags, char *res)
{
	int	i;
	int	n;
	int negatif;
	
	i = 0;
	n = 0;
	negatif = 0;
	if (res[0] == '-')
		negatif = 1;
	while (i++ < catch_flags->dot_val - ft_strlen(res) + negatif)
		n += write(1, "0", 1);
	return (n);
}

int	get_max(t_flags *catch_flags, char *res)
{
	int	max;

	if ((ft_strlen(res)) > catch_flags->dot_val)
		max = ft_strlen(res);
	else
		max = catch_flags->dot_val;
	return (max);
}
 