/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:27:05 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 14:27:06 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char*)s;
	while (*res != (char)c)
	{
		if (*res == '\0')
			return (NULL);
		res++;
	}
	return (res);
}
