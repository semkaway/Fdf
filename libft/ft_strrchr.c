/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:47:50 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/03 09:38:56 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ch;

	ch = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ch = (char*)s;
		s++;
	}
	if (*s == (char)c)
		ch = (char*)s;
	return (ch);
}
