/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 22:13:21 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 22:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	signe;

	res = 0;
	signe = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		signe = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (48 <= *str && *str <= 57)
	{
		res *= 10;
		res += (*str - 48);
		str++;
	}
	res *= signe;
    return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_bzero(void *ptr, size_t num)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) ptr;
	while (i < num)
	{
		p[i] = (unsigned char) 0;
		i++;
	}
	return (ptr);
}