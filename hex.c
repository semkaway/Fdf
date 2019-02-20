/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:28:54 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/08 17:28:57 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_int_map_with_0(int **int_map, int a, t_s *e)
{
	int		i;

	i = 0;
	int_map[a] = (int*)malloc(sizeof(int) * e->c);
	while (i < e->c)
	{
		int_map[a][i] = e->color;
		i++;
	}
}

extern int		**create_color_int_arr(t_s *e)
{
	int		**int_map;
	int		m;

	m = 0;
	int_map = (int**)malloc(sizeof(int*) * e->r);
	while (m < e->r)
	{
		fill_int_map_with_0(int_map, m, e);
		m++;
	}
	return (int_map);
}

static int		square(int i, int power)
{
	int		count;
	int		res;

	count = 0;
	res = 1;
	if (power == 0)
		return (1);
	while (count < power)
	{
		res *= i;
		count++;
	}
	return (res);
}

static int		find_number(char c)
{
	int		current;

	if (ft_isdigit(c) == 1)
		current = c - 48;
	else
	{
		c = ft_tolower(c);
		current = c - 87;
	}
	return (current);
}

extern int		hex_to_dec(char *s)
{
	int		res;
	int		current;
	size_t	power;
	int		len;
	int		storage[6];

	len = ft_strlen(s) - 1;
	power = 0;
	res = 0;
	while (len >= 0)
	{
		current = find_number(s[len]);
		storage[power] = current * square(16, power);
		power++;
		len--;
	}
	power = 0;
	while (power < ft_strlen(s))
	{
		res += storage[power];
		power++;
	}
	return (res);
}
