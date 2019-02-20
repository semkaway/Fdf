/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:51:04 by kvilna            #+#    #+#             */
/*   Updated: 2017/12/15 11:02:35 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

extern void		free_func(t_s *e)
{
	set_them_free((void**)e->int_map, e->r);
	set_them_free((void**)e->index, e->r);
	set_them_free((void**)e->map, e->r);
	free(e->user_color);
}

extern void		set_them_free(void **nums, int times)
{
	int		i;

	i = 0;
	while (i < times)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

static int		count_rows(char **map)
{
	int		count;

	count = 0;
	while (*map)
	{
		count++;
		map++;
	}
	return (count);
}

static void		fill_int_map(int **int_map, int a, char *map, t_s *e)
{
	char	**nums;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nums = ft_strsplit(map, ' ');
	int_map[a] = (int*)malloc(sizeof(int) * e->c);
	while (nums[j])
	{
		int_map[a][i] = ft_atoi(nums[j]);
		if (int_map[a][i] < e->z_min)
			e->z_min = int_map[a][i];
		if (int_map[a][i] > e->z_max)
			e->z_max = int_map[a][i];
		j++;
		i++;
	}
	set_them_free((void**)nums, e->c);
}

extern int		**create_int_arr(t_s *e)
{
	int		**int_map;
	int		a;
	int		m;

	e->z_min = 0;
	e->z_max = 0;
	a = 0;
	m = 0;
	e->c = ft_count_words(*e->map, ' ');
	e->r = count_rows(e->map);
	int_map = (int**)malloc(sizeof(int *) * e->r);
	while (e->map[m])
	{
		fill_int_map(int_map, a, e->map[m], e);
		a++;
		m++;
	}
	return (int_map);
}
