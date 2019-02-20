/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 10:08:30 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/01 10:08:32 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char*)malloc(sizeof(*new) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
