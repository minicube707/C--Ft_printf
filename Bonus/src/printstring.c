/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:17:06 by marvin            #+#    #+#             */
/*   Updated: 2025/12/13 01:28:49 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printstring_minus(t_flags *catch_flags, char *string)
{
	int	i;
	int	n;
	int	len;

	i = -1;
	n = 0;
	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	while (++i < len)
		n += write(1, &string[i], 1);
	while (i++ < catch_flags->number)
		n += write(1, " ", 1);
	return (n);
}

static int	printstring_dot(t_flags *catch_flags, char *string)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (string == NULL && catch_flags->dot_val > 5)
		string = "(null)";
	if (string == NULL && catch_flags->dot_val <= 5)
		string = "";
	while (i < catch_flags->dot_val && string[i] != '\0')
	{
		n += write(1, &string[i], 1);
		i++;
	}
	return (n);
}

static int	printstring_num(t_flags *catch_flags, char *string)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = 0;
	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	while (i++ < catch_flags->number - len)
		n += write(1, " ", 1);
	i = -1;
	while (++i < len)
		n += write(1, &string[i], 1);
	return (n);
}

static int	printstring_else(char *string)
{
	int	i;
	int	n;
	int	len;

	i = -1;
	n = 0;
	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	while (++i < len)
		n += write(1, &string[i], 1);
	return (n);
}

int	printstring(t_flags *catch_flags, char *string)
{
	if (catch_flags->dot)
		return (printstring_dot(catch_flags, string));
	if (catch_flags->minus)
		return (printstring_minus(catch_flags, string));
	if (catch_flags->number != 0)
		return (printstring_num(catch_flags, string));
	return (printstring_else(string));
}
