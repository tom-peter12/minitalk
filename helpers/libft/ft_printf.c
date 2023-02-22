/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:09:11 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 13:09:15 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	a_list;
	int		count;

	va_start(a_list, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_writer(a_list, *str);
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(a_list);
	return (count);
}
