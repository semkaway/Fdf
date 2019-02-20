/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:17:18 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/02 12:17:20 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	size_t			length(char *str)
{
	int			i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

static int				num_int(int i)
{
	int			count;
	long long	k;

	count = 1;
	k = i;
	if (k < 0)
	{
		k *= -1;
		count++;
	}
	if (k >= 0 && k <= 9)
		return (count);
	while (k > 9)
	{
		k = k / 10;
		count++;
	}
	return (count);
}

static void				fix(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = length(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

char					*ft_itoa(int n)
{
	char		*res;
	int			j;
	int			i;
	long long	k;

	k = n;
	i = 0;
	j = 0;
	if (!(res = (char*)malloc(sizeof(*res) * (num_int(k) + 1))))
		return (NULL);
	if (k < 0 && (k *= -1))
		j = 1;
	res[i] = k % 10 + '0';
	i++;
	while ((k /= 10) > 0 && (res[i] = k % 10 + '0'))
		i++;
	if (j == 1 && (res[i] = '-'))
		i++;
	res[i] = '\0';
	fix(res);
	return (res);
}
