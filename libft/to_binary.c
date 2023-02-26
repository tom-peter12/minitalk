/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:18:05 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/23 21:18:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
