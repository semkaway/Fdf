/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:33:37 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/10 13:43:29 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	fill(void *s, size_t n)
{
	size_t	i;
	char	*new;

	new = (char *)s;
	i = 0;
	while (i < n)
	{
		new[i] = 0;
		i++;
	}
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(size * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	fill(ptr, size);
	return (ptr);
}
