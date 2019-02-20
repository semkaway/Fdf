/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:30:42 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/16 12:30:43 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_with_color(t_s *e, int storage[5][3])
{
	int		i;
	int		j;
	float	third;

	i = -1;
	third = e->z_max / 3;
	while (++i < e->r)
	{
		j = -1;
		while (++j < e->c)
		{
			if (e->int_map[i][j] >= e->z_min
				&& e->int_map[i][j] <= 0)
				e->index[i][j] = storage[e->storage_num][0];
			if (e->int_map[i][j] > 0
				&& e->int_map[i][j] <= third)
				e->index[i][j] = storage[e->storage_num][1];
			if (e->int_map[i][j] > third
				&& e->int_map[i][j] <= third * 2)
				e->index[i][j] = storage[e->storage_num][2];
			if (e->int_map[i][j] > third * 2)
				e->index[i][j] = 0xffffff;
		}
	}
}

static void		fill_color_arr(int storage[5][3])
{
	storage[0][0] = 0xff0000;
	storage[0][1] = 0xff5e5e;
	storage[0][2] = 0xff6d69;
	storage[1][0] = 0xff00;
	storage[1][1] = 0x3fff3f;
	storage[1][2] = 0x7eff7e;
	storage[2][0] = 0xff;
	storage[2][1] = 0x3f3fff;
	storage[2][2] = 0x7e7eff;
	storage[3][0] = 0x4b39a2;
	storage[3][1] = 0x1d592f;
	storage[3][2] = 0x8e400d;
	storage[4][0] = 0x4c1c6c;
	storage[4][1] = 0x5b108a;
	storage[4][2] = 0x9101ed;
}

static void		fill_color_arr_hex(int storage[5][3], int res)
{
	float	*steps;

	steps = hex_to_rgb(res, 0xffffff, 4);
	storage[5][0] = res;
	storage[5][1] = rgb_to_hex(res, steps);
	storage[5][2] = rgb_to_hex(storage[5][1], steps);
	free(steps);
}

static void		get_hex(char *s, int storage[5][3])
{
	char	hex[13];
	int		a;
	int		i;
	char	color[7];
	int		res;

	ft_strcpy(hex, "aAbBcCdDeEfF");
	a = 0;
	i = 2;
	while (s[i])
	{
		color[a] = s[i];
		a++;
		i++;
		if (i > 8)
			usage_message("Please, enter a valid color code.", 2, 42);
	}
	res = hex_to_dec(color);
	fill_color_arr_hex(storage, res);
}

extern int		colors(t_s *e)
{
	int		storage[5][3];

	e->storage_num = 13;
	fill_color_arr(storage);
	if (ft_strcmp(e->user_color, "red") == 0)
		e->storage_num = 0;
	if (ft_strcmp(e->user_color, "green") == 0)
		e->storage_num = 1;
	if (ft_strcmp(e->user_color, "blue") == 0)
		e->storage_num = 2;
	if (ft_strcmp(e->user_color, "nature") == 0)
		e->storage_num = 3;
	if (ft_strcmp(e->user_color, "default") == 0)
		e->storage_num = 4;
	if (ft_strcmp(e->user_color, "none") == 0)
		return (0);
	if (e->user_color[0] == '0')
	{
		e->storage_num = 5;
		get_hex(e->user_color, storage);
	}
	else if (e->storage_num == 13)
		usage_message("wrong color", 2, 42);
	fill_with_color(e, storage);
	return (0);
}
