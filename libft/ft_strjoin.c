/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:46:32 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/01 11:46:34 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		length(const char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char*)malloc(sizeof(new) * (length(s1) + length(s2)) + 1);
	if (s1 == NULL || s2 == NULL || new == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
