/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:24:08 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 16:18:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verification(const char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = "cspdiuxX%";
	while (tab[i] != 0)
	{
		if (tab[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
