/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:43 by fmotte            #+#    #+#             */
/*   Updated: 2025/12/12 18:05:21 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	type;
	int	minus;
	int	dot;
	int	number;
	int	plus;
	int	space;
	int	sharp;
	int	zeros;
}		t_flags;

int		ft_printf(const char *str, ...);
int		get_flags(t_flags *catch_flags, const char *string, int *j);
void	reset_flags(t_flags *catch_flags);
int		manage_string(va_list arg, t_flags *catch_flags);

/*Mini Libft*/
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_bzero(void *ptr, size_t num);

/*Print*/
int		printchar(t_flags *catch_flags, char c);
int		printstring(t_flags *catch_flags, char *string);
int		printmemory(t_flags *catch_flags, void *addr);
int		printinteger(t_flags *catch_flags, int num);
int		printunsignedinteger(t_flags *catch_flags, unsigned int num);
int		printhexadecimal(t_flags *catch_flags, unsigned int num, int mode);

char	*ft_puthexnbr(char *string, unsigned long nb, int mode);
char	*ft_putnbr(char *string, int nb);

int		printinteger_minus(t_flags *catch_flags, int max);
int		printinteger_dot(t_flags *catch_flags, char *res);

int		get_max(t_flags *catch_flags, char *res);

#endif
