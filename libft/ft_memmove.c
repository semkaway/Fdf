/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:19:58 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/10 13:14:21 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*s;

	dest = (char*)dst;
	s = (char*)src;
	if (s == dest || n == 0)
		return (dest);
	if (s < dest)
	{
		while (--n)
			dest[n] = s[n];
		dest[0] = s[0];
	}
	else
	{
		i = 0;
		while (i < n && (dest[i] = s[i]))
			i++;
	}
	return (dest);
}
