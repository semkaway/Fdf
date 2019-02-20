/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:31:36 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/05 15:31:39 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**new coordinates by z
*/

extern void		byz(t_s *e, float x[e->r][e->c],
		float y[e->r][e->c], float z[e->r][e->c])
{
	int		i;
	int		j;
	float	l;

	i = 0;
	l = e->an * (M_PI / 180);
	while (i < e->r)
	{
		j = 0;
		while (j < e->c)
		{
			x[i][j] = new_pos_x_z(j, i, e->an);
			y[i][j] = new_pos_y_z(j, i, e->an);
			if (e->an > 0)
				z[i][j] = -(e->int_map[i][j]);
			else
				z[i][j] = e->int_map[i][j];
			if (e->z_min <= -10 || e->z_max >= 10)
				z[i][j] /= 6;
			j++;
		}
		i++;
	}
}

/*
**new coordinates by x
*/

extern void		turn_by_x(t_s *e, float y[e->r][e->c], float z[e->r][e->c])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->r)
	{
		j = 0;
		while (j < e->c)
		{
			y[i][j] = new_pos_y_x(z[i][j], y[i][j], e->an);
			z[i][j] = new_pos_z_x(z[i][j], y[i][j], e->an);
			j++;
		}
		i++;
	}
}
