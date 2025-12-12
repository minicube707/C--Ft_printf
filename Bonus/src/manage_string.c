/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:44:42 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 17:42:05 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_string(va_list arg, t_flags *catch_flags)
{
	if (catch_flags->type == 1)
		return (printchar(catch_flags, va_arg(arg, int)));
	if (catch_flags->type == 2)
		return (printstring(catch_flags, va_arg(arg, char *)));
	if (catch_flags->type == 3)
		return (printmemory(catch_flags, va_arg(arg, void *)));
	if (catch_flags->type == 4 || catch_flags->type == 5)
		return (printinteger(catch_flags, va_arg(arg, int)));
	if (catch_flags->type == 6)
		return (printunsignedinteger(catch_flags, va_arg(arg, unsigned int)));
	if (catch_flags->type == 7)
		return (printhexadecimal(catch_flags, va_arg(arg, unsigned int), 0));
	if (catch_flags->type == 8)
		return (printhexadecimal(catch_flags, va_arg(arg, unsigned int), 1));
	if (catch_flags->type == 9)
		return (write(1, "%%", 1));
	return (0);
}
