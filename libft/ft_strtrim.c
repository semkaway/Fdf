/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:25:44 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/01 13:35:24 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t		length(const char *s)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s)
		return (NULL);
	len = length(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	j = 0;
	while (j < len && (new[j] = s[i]))
	{
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
