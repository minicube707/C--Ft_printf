/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthxnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:43:13 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 13:29:45 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthxnbr(unsigned int nb, int mode, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (mode)
		base = "0123456789ABCDEF";
	if (nb > 15)
	{
		len = ft_puthxnbr(nb / 16, mode, len);
		ft_puthxnbr(nb % 16, mode, len);
	}
	else
		write(1, &base[nb], 1);
	return (len + 1);
}
