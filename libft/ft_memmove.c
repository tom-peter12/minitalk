/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:07:20 by tpetros           #+#    #+#             */
/*   Updated: 2022/10/15 15:04:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!((char *) src) && !((char *) dst) && len > 0)
		return (0);
	if (((char *) dst) < ((char *) src))
		ft_memcpy(((char *) dst), ((char *) src), len);
	else
	{
		while (len-- > 0)
			((char *) dst)[len] = ((char *) src)[len];
	}
	return (dst);
}
