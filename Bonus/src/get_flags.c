/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:50:51 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 17:47:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(t_flags *catch_flags)
{
	catch_flags->dot = 0;
	catch_flags->minus = 0;
	catch_flags->number = 0;
	catch_flags->plus = 0;
	catch_flags->sharp = 0;
	catch_flags->space = 0;
	catch_flags->type = 0;
	catch_flags->zeros = 0;
}

int	in(char *string, char c)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	get_flags_catch_type(t_flags *catch_flags, const char *string)
{
	if (string[0] == 'c')
		catch_flags->type = 1;
	else if (string[0] == 's')
		catch_flags->type = 2;
	else if (string[0] == 'p')
		catch_flags->type = 3;
	else if (string[0] == 'd')
		catch_flags->type = 4;
	else if (string[0] == 'i')
		catch_flags->type = 5;
	else if (string[0] == 'u')
		catch_flags->type = 6;
	else if (string[0] == 'x')
		catch_flags->type = 7;
	else if (string[0] == 'X')
		catch_flags->type = 8;
	else if (string[0] == '%')
		catch_flags->type = 9;
	else
		catch_flags->type = 0;
}

static void	get_flags_utils(t_flags *catch_flags, const char *string, int i,
		int *dot)
{
	if (ft_isdigit((int)string[i]) && !(*dot))
		catch_flags->number = (string[i] - 48) + (catch_flags->number * 10);
	if (ft_isdigit((int)string[i]) && (*dot))
		catch_flags->dot = (string[i] - 48) + (catch_flags->dot * 10);
	else if (string[i] == '.')
		*dot = 1;
	else if (string[i] == '-')
		catch_flags->minus = 1;
	else if (string[i] == '+')
		catch_flags->plus = 1;
	else if (string[i] == '#')
		catch_flags->sharp = 1;
	else if (string[i] == ' ')
		catch_flags->space = 1;
	else if (catch_flags->number == 0 && string[i] == '0')
		catch_flags->zeros = 1;
}

int	get_flags(t_flags *catch_flags, const char *string, int *j)
{
	char	*allow_char;
	int		i;
	int		dot;

	allow_char = "0123456789.-+# ";
	i = 0;
	dot = 0;
	while (string[i] != 0 && !in("cspdiuxX%", string[i]))
	{
		if (!in(allow_char, string[i]))
			return (1);
		get_flags_utils(catch_flags, string, i, &dot);
		i++;
		(*j)++;
	}
	get_flags_catch_type(catch_flags, &string[i]);
	(*j)++;
	return (0);
}
