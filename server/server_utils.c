/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:28:35 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/20 18:28:36 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	to_char(char *str)
{
	int	i;
	int	c;
	int len;

	i = 0;
	c = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		c = c + (ft_iterative_power(2, len - i - 1) * (str[i] - '0'));
		i++;
	}
	return (c);
}

int	ft_iterative_power(int nb, int power)
{
	int	multiplier;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power == 1)
		return (nb);
	multiplier = nb;
	while (power > 1)
	{
		nb = multiplier * nb;
		power--;
	}
	return (nb);
}
