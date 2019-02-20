/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:27:59 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/18 16:36:00 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

extern void		position(t_s *e)
{
	if (e->an < 0)
	{
		e->width -= (e->width / 1.1);
		e->height += 100;
	}
	e->d = e->height / 4;
	e->d2 = e->width / 2;
}

static void		act(t_s *e, t_pos p, float x[e->r][e->c], float y[e->r][e->c])
{
	p.x1 = x[p.i][p.j] * e->k + e->d2;
	p.y1 = y[p.i][p.j] * e->k + e->d;
	p.x2 = x[p.i][p.j + 1] * e->k + e->d2;
	p.y2 = y[p.i][p.j + 1] * e->k + e->d;
	e->color = e->index[p.i][p.j];
	e->next_color = e->index[p.i][p.j + 1];
	bres(p, e);
	e->next_color = e->index[p.i + 1][p.j];
	p.x2 = x[p.i + 1][p.j] * e->k + e->d2;
	p.y2 = y[p.i + 1][p.j] * e->k + e->d;
	bres(p, e);
}

static void		last_line(t_s *e, t_pos p,
				float x[e->r][e->c], float y[e->r][e->c])
{
	p.j = 0;
	while (p.j + 1 < e->c)
	{
		e->color = e->index[p.i][p.j];
		e->next_color = e->index[p.i][p.j + 1];
		p.x1 = x[p.i][p.j] * e->k + e->d2;
		p.y1 = y[p.i][p.j] * e->k + e->d;
		p.x2 = x[p.i][p.j + 1] * e->k + e->d2;
		p.y2 = y[p.i][p.j + 1] * e->k + e->d;
		bres(p, e);
		p.j++;
	}
	mlx_pixel_put(e->mlx, e->win, p.x2, p.y2, e->next_color);
}

extern void		start_drawing(t_s *e, float x[e->r][e->c], float y[e->r][e->c])
{
	t_pos	p;

	p.i = -1;
	while (++p.i + 1 < e->r)
	{
		p.j = -1;
		while (++p.j + 1 < e->c)
			act(e, p, x, y);
		e->color = e->index[p.i][p.j];
		e->next_color = e->index[p.i + 1][p.j];
		p.x1 = x[p.i][p.j] * e->k + e->d2;
		p.y1 = y[p.i][p.j] * e->k + e->d;
		p.x2 = x[p.i + 1][p.j] * e->k + e->d2;
		p.y2 = y[p.i + 1][p.j] * e->k + e->d;
		bres(p, e);
	}
	last_line(e, p, x, y);
}

extern void		draw_mult_lines(t_s *e)
{
	float	x[e->r][e->c];
	float	y[e->r][e->c];
	float	z[e->r][e->c];

	byz(e, x, y, z);
	turn_by_x(e, y, z);
	start_drawing(e, x, y);
}
