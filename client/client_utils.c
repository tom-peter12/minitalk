/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:13:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/18 20:13:05 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*to_binary(int c)
{
	char	*bin_holder;
	int		h;

	bin_holder = (char *)ft_calloc(9, 1);
	h = 0;
	while (c > 0)
	{
		h = c % 2;
		bin_holder = ft_strjoin(bin_holder, ft_itoa(h));
		c = c / 2;
	}
	while (8 - ft_strlen(bin_holder))
	{
		bin_holder = ft_strjoin(bin_holder, "0");
	}
	return (ft_strrev(bin_holder));
}

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	len -= 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return (str);
}
