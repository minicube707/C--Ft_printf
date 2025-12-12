/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexdecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:00:08 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 01:00:08 by marvin           ###   ########.fr       */
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

static int printhexadecimal_minus(t_flags *catch_flags, int max)
{   
    int i;
    int n;

    i = 0;
    n = 0;
    while (i++ < catch_flags->number - max - catch_flags->plus && catch_flags->minus)
        n += write(1, " ", 1);
    return (n);
}

static int printhexadecimal_dot(t_flags *catch_flags, char *res)
{   
    int i;
    int n;

    i = 0;
    n = 0;
    while (i++ < catch_flags->dot - ft_strlen(res))
        n += write(1, "0", 1);
    return (n);
}

static int printhexadecimal_skip_begin(t_flags *catch_flags, int max)
{   
    int i;
    int n;

    n = 0;
    i = 0;
    while (i++ < catch_flags->number - max - catch_flags->space - catch_flags->plus && !catch_flags->minus && !catch_flags->zeros)
        n += write(1, " ", 1);
    i = 0;
    while (i++ < catch_flags->number - max - catch_flags->space - catch_flags->plus && !catch_flags->minus && catch_flags->zeros)
        n += write(1, "0", 1);
    return (n);
}

static int get_max(t_flags *catch_flags, char *res)
{
    int max;

    if ((ft_strlen(res)) > catch_flags->dot)
        max = ft_strlen(res);
    else
        max = catch_flags->dot;
    return (max);
}

int printhexadecimal(t_flags *catch_flags, unsigned int num, int mode)
{
	int n;
    int max;
    char buff[11];
    char *res;

    ft_bzero(buff, 11);
    res = ft_puthexnbr(buff, num, mode);
    max = get_max(catch_flags, res);
    n = 0;
    n += printhexadecimal_skip_begin(catch_flags, max);
    n += printhexadecimal_dot(catch_flags, res);
    n += write(1, res, ft_strlen(res));
    n += printhexadecimal_minus(catch_flags, max);
    return (n);
}