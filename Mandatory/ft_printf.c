/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:20:57 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 16:16:01 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	int		n;
	va_list	args;

	i = 0;
	n = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i] != 0)
	{
		if (str[i] != '%')
			n += write(1, &str[i], 1);
		else
		{
			l = verification(str[i + 1]);
			n += show(args, l);
			i++;
		}
		i++;
	}
	va_end(args);
	return (n);
}
