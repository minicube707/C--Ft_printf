/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:43 by fmotte            #+#    #+#             */
/*   Updated: 2025/05/16 16:19:12 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		show(va_list arg, int letter);
char	*ft_strchr(const char *s, int c);
int		verification(const char c);
int		ft_putnbr(int nb, int len);
int		ft_putpnbr(unsigned int nb, int len);
int		ft_putstr(char *str);
void	ft_putchar(char c);
int		putmemory(void *addr);
int		ft_puthxnbr(unsigned int str, int mode, int len);

#endif
