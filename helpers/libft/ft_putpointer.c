/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:22:03 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 18:22:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_writehex(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += ft_writehex(ptr / 16);
		count += ft_writehex(ptr % 16);
	}
	else if (ptr > 9)
		count += ft_putchar(ptr - 10 + 'a');
	else
		count += ft_putchar(ptr + '0');
	return (count);
}

int	ft_putpointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
	{
		count += ft_writehex(ptr);
	}
	return (count);
}
