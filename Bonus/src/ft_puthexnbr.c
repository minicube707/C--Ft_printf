/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:49:47 by fmotte            #+#    #+#             */
/*   Updated: 2025/12/12 18:06:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthexnbr(char *string, unsigned long nb, int mode)
{
	char	*base;

	if (mode)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb > 15)
	{
		string = ft_puthexnbr(string, nb / 16, mode);
		ft_puthexnbr(string, nb % 16, mode);
	}
	else
		string[ft_strlen(string)] = base[nb];
	return (string);
}
