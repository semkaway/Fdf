/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:38:56 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 08:43:52 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*s;

	i = 0;
	dest = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
