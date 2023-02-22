/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:06:27 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 20:06:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	i;
	int	nb;

	nb = n;
	if (nb == INT_MIN)
	{
		ft_putstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		i = nb + 48;
		ft_putchar(i);
	}
	return (ft_lennbr(n));
}
