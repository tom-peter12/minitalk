/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:34:11 by tomas             #+#    #+#             */
/*   Updated: 2023/02/27 17:34:12 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

char	*to_binary(unsigned int c)
{
	char			*bin_holder;
	unsigned int	h;
	char			*temp;

	bin_holder = (char *)ft_calloc(9, 1);
	h = 0;
	while (c > 0)
	{
		h = c % 2;
		temp = ft_itoa(h);
		bin_holder = ft_strjoin(bin_holder, temp);
		c = c / 2;
		free(temp);
	}
	while (8 - ft_strlen(bin_holder))
	{
		bin_holder = ft_strjoin(bin_holder, "0");
	}
	return (ft_strrev(bin_holder));
}
