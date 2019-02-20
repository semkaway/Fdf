/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 11:53:13 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/02 11:53:20 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char			*copy_string(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != '\0')
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int			wordcount(const char *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (s[0] == '\0')
		return (words);
	if (s[i] != c)
	{
		words++;
		i++;
	}
	while (s[i] == c && s[i + 1] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c) && (s[i] == c && s[i + 1] != '\0'))
			words++;
		i++;
	}
	return (words);
}

static size_t		letters(char *s, char c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s == c)
		s++;
	while (*s != '\0' && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static char			*fill(char *s1, char c)
{
	int		i;
	int		j;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(*new) * (letters(s1, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] == c)
		i++;
	while (s1[i] != '\0' && s1[i] != c)
	{
		new[j] = s1[i];
		s1[i] = c;
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*copy;
	int		words;
	int		i;

	i = 0;
	if (!s || !(copy = (char*)malloc(sizeof(copy) * (ft_strlen(s) + 1))))
		return (NULL);
	copy_string(copy, s);
	words = wordcount(copy, c);
	if ((res = (char**)malloc(sizeof(res) * (ft_strlen(copy) + 1))) == NULL)
		return (NULL);
	while (i < words)
	{
		res[i] = fill(copy, c);
		if (res[i] == NULL)
		{
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	free(copy);
	return (res);
}
