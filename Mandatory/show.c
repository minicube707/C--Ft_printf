/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:26:40 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 12:54:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	show(va_list arg, int letter)
{
	if (letter == 1)
		return (write(1, &(char){va_arg(arg, int)}, 1));
	else if (letter == 2)
		return (ft_putstr(va_arg(arg, char *)));
	else if (letter == 3)
		return (putmemory(va_arg(arg, void *)));
	else if (letter == 4 || letter == 5)
		return (ft_putnbr(va_arg(arg, int), 0));
	else if (letter == 6)
		return (ft_putpnbr(va_arg(arg, unsigned int), 0));
	else if (letter == 7)
		return (ft_puthxnbr(va_arg(arg, unsigned long), 0, 0));
	else if (letter == 8)
		return (ft_puthxnbr(va_arg(arg, unsigned long), 1, 0));
	else if (letter == 9)
		return (write(1, "%", 1));
	else
		return (-1);
}
