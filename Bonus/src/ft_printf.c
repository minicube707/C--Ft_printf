/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:20:57 by fmotte            #+#    #+#             */
/*   Updated: 2025/12/12 17:47:24 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	args;
	t_flags	catch_flags;

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
			reset_flags(&catch_flags);
			if (get_flags(&catch_flags, &str[i + 1], &i))
				return (-1);
			n += manage_string(args, &catch_flags);
		}
		i++;
	}
	va_end(args);
	return (n);
}
