/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:32:09 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 16:11:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int len)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			nb = -147483648;
			ft_putchar('2');
			len += 1;
		}
		len = ft_putnbr(-nb, len);
	}
	else if (nb > 9)
	{
		len = ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + 48);
	return (len + 1);
}
