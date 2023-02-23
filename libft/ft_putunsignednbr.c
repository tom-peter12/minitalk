/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:14:00 by tpetros           #+#    #+#             */
/*   Updated: 2023/01/10 20:14:02 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(unsigned int nb)
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

int	ft_putunsignednbr(unsigned int unb)
{
	if (unb > 9)
	{
		ft_putunsignednbr(unb / 10);
		ft_putunsignednbr(unb % 10);
	}
	else
		ft_putchar(unb + '0');
	return (ft_lennbr(unb));
}
