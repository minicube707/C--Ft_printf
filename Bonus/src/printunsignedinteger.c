/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsignedinteger.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 01:23:44 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 01:23:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_putusignednnbr(char *string, unsigned int nb)
{
	if (nb > 9)
	{
        string = ft_putusignednnbr(string, nb / 10);
		ft_putusignednnbr(string, nb % 10);
	}
	else
        string[ft_strlen(string)] = nb + 48;
	return (string);
}

static int printinteger_minus(t_flags *catch_flags, int max)
{   
    int i;
    int n;

    i = 0;
    n = 0;
    while (i++ < catch_flags->number - max - catch_flags->plus && catch_flags->minus)
        n += write(1, " ", 1);
    return (n);
}

static int printinteger_dot(t_flags *catch_flags, char *res)
{   
    int i;
    int n;

    i = 0;
    n = 0;
    while (i++ < catch_flags->dot - ft_strlen(res))
        n += write(1, "0", 1);
    return (n);
}

static int printinteger_skip_begin(t_flags *catch_flags, int max)
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

int printunsignedinteger(t_flags *catch_flags, unsigned int num)
{
    int n;
    int max;
    char buff[11];
    char *res;

    ft_bzero(buff, 11);
    res = ft_putusignednnbr(buff, num);
    max = get_max(catch_flags, res);
    n = 0;
    n += printinteger_skip_begin(catch_flags, max);
    n += printinteger_dot(catch_flags, res);
    n += write(1, res, ft_strlen(res));
    n += printinteger_minus(catch_flags, max);
    return (n);
}