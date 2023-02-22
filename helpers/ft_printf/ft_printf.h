/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:11:25 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 13:11:27 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_writer(va_list ap, char c);
int		ft_putunsignednbr(unsigned int unb);
int		ft_puthex(unsigned int num, const char format);
int		ft_putpointer(unsigned long long p);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *str);

#endif