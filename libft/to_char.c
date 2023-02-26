/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:13:44 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/23 21:13:49 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_char(char *str)
{
	int	i;
	int	c;
	int	len;

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
