/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:39:10 by tpetros           #+#    #+#             */
/*   Updated: 2022/10/15 15:09:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)src;
	character = (unsigned char)c;
	while (*str != character)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
