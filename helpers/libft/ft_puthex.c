/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:16:16 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 20:16:17 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_hex(unsigned int num, const char format)
{
	int	count;

	count = 0;
	if (num >= 16)
	{
		count += ft_put_hex(num / 16, format);
	}
	num = num % 16;
	if (num < 16)
	{
		if (num <= 9)
			count += ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				count += ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				count += ft_putchar((num - 10 + 'A'));
		}
	}
	return (count);
}

int	ft_puthex(unsigned int num, const char format)
{
	int	count;

	count = 0;
	if (num == 0)
		return (ft_putchar((num + '0')));
	else
		count += ft_put_hex(num, format);
	return (count);
}
