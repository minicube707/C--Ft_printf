/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmemory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:34:45 by marvin            #+#    #+#             */
/*   Updated: 2025/12/13 00:05:08 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printmemory_minus(t_flags *catch_flags, unsigned long nb, char *res)
{
	int	n;
	int	i;

	if (nb != 0)
	{
		n = write(1, "0x", 2);
		n += write(1, res, ft_strlen(res));
	}
	else
		n = write(1, "(nil)", 5);
	i = n;
	while (i++ < catch_flags->number)
		n += write(1, " ", 1);
	return (n);
}

static int	printmemory_num(t_flags *catch_flags, unsigned long nb, char *res)
{
	int	i;
	int	n;
	int	m;

	if (nb != 0)
		n = 14;
	else
		n = 5;
	i = 0;
	m = n;
	while (i++ < catch_flags->number - m)
		n += write(1, " ", 1);
	if (nb != 0)
	{
		write(1, "0x", 2);
		write(1, res, ft_strlen(res));
	}
	else
		write(1, "(nil)", 5);
	return (n);
}

static int	printmemory_else(unsigned long nb, char *res)
{
	int	n;

	if (nb != 0)
	{
		n = write(1, "0x", 2);
		n += write(1, res, ft_strlen(res));
	}
	else
		n = write(1, "(nil)", 5);
	return (n);
}

int	printmemory(t_flags *catch_flags, void *addr)
{
	unsigned char	*cast;
	unsigned long	address;
	char			buff[17];
	char			*res;

	(void)catch_flags;
	cast = (unsigned char *)addr;
	address = (unsigned long)&cast[0];
	ft_bzero(buff, 17);
	res = ft_puthexnbr(buff, address, 0);
	if (catch_flags->minus)
		return (printmemory_minus(catch_flags, address, res));
	if (catch_flags->number != 0)
		return (printmemory_num(catch_flags, address, res));
	return (printmemory_else(address, res));
}
