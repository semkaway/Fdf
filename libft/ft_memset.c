/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:20:25 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 09:07:23 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*new;

	new = (char *)b;
	i = 0;
	if (len == 0)
		return (b);
	while (i < len)
	{
		new[i] = (char)c;
		i++;
	}
	return (new);
}
