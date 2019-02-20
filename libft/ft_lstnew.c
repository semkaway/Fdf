/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 08:28:38 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/06 08:30:55 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		*copy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	i = 0;
	dest = (char*)dst;
	source = (const char*)src;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = malloc(content_size);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	copy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
