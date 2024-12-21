/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 21:05:55 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/14 19:03:31 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putnbr_ui(unsigned int u);
ssize_t	ft_putptr(uintptr_t p);
ssize_t	ft_puthex(unsigned long x, int is_lower);

char	ft_dec_to_lower_hex(unsigned int u);
char	ft_dec_to_upper_hex(unsigned int u);

#endif
