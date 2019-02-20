/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:17:24 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 08:56:54 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	ch;

	new = (unsigned char*)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*new == ch)
			return (new);
		new++;
		i++;
	}
	return (0);
}
