/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmemory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:34:53 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 16:21:39 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putmem(unsigned long nb, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
	{
		len = ft_putmem(nb / 16, len);
		ft_putmem(nb % 16, len);
	}
	else
		write(1, &base[nb], 1);
	return (len + 1);
}

int	putmemory(void *addr)
{
	unsigned char	*cast;
	unsigned long	address;
	int				n;

	n = 2;
	cast = (unsigned char *) addr;
	address = (unsigned long) &cast[0];
	if (address == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	n += ft_putmem(address, 0);
	return (n);
}
