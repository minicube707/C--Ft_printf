/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:32:09 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 13:30:43 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpnbr(unsigned int nb, int len)
{
	if (nb > 9)
	{
		len = ft_putpnbr(nb / 10, len);
		ft_putpnbr(nb % 10, len);
	}
	else
		ft_putchar(nb + 48);
	return (len + 1);
}
