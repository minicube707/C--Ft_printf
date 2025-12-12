/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:48:44 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 22:48:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printchar(t_flags *catch_flags, char c)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if (!catch_flags->minus)
    {
        while (i++ < catch_flags->number - 1)
            n += write(1, " ", 1); 
        n += write(1, &c, 1); 
        return (n);
    }
    n += write(1, &c, 1);
    if (catch_flags->minus)
    {
        while (i++ < catch_flags->number - 1)
            n += write(1, " ", 1);    
    }
    return (n); 
}