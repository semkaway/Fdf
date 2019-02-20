/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:37:40 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/11 14:37:45 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

extern float	*hex_to_rgb(int start, int end, float line)
{
	t_px	start_color;
	t_px	end_color;
	float	*steps;

	steps = (float*)malloc(sizeof(float) * 3);
	start_color.r = (start >> 16);
	start_color.g = ((start >> 8) & 0xFF);
	start_color.b = ((start) & 0xFF);
	end_color.r = (end >> 16);
	end_color.g = ((end >> 8) & 0xFF);
	end_color.b = ((end) & 0xFF);
	steps[0] = (end_color.r - start_color.r) / line;
	steps[1] = (end_color.g - start_color.g) / line;
	steps[2] = (end_color.b - start_color.b) / line;
	return (steps);
}

extern int		rgb_to_hex(int start, float *steps)
{
	int		hex;
	t_px	final_color;
	t_px	start_color;

	hex = 0;
	start_color.r = ((start >> 16));
	start_color.g = ((start >> 8) & 0xFF);
	start_color.b = ((start) & 0xFF);
	final_color.r = start_color.r + steps[0];
	final_color.g = start_color.g + steps[1];
	final_color.b = start_color.b + steps[2];
	if (final_color.r < 0)
		final_color.r = 0;
	if (final_color.g < 0)
		final_color.g = 0;
	if (final_color.b < 0)
		final_color.b = 0;
	hex += final_color.r;
	hex *= 0x100;
	hex += final_color.g;
	hex *= 0x100;
	hex += final_color.b;
	return (hex);
}

static int		line_len(t_pos p, t_bres o)
{
	t_bres	b;
	int		count;

	count = 1;
	b.deltax = abs(p.x2 - p.x1);
	b.deltay = abs(p.y2 - p.y1);
	b.error = b.deltax - b.deltay;
	b.signx = o.signx;
	b.signy = o.signy;
	while (p.x1 != p.x2 || p.y1 != p.y2)
	{
		b.error2 = b.error * 2;
		if (b.error2 > -b.deltay)
		{
			b.error -= b.deltay;
			p.x1 += b.signx;
		}
		if (b.error2 < b.deltax)
		{
			b.error += b.deltax;
			p.y1 += b.signy;
		}
		count++;
	}
	return (count);
}

static void		drawing(t_pos p, t_help mew, t_bres o, t_s *e)
{
	while ((p.x1 != p.x2 || p.y1 != p.y2))
	{
		mew.color_change = mew.color;
		mlx_pixel_put(e->mlx, e->win, p.x1, p.y1, mew.color);
		o.error2 = o.error * 2;
		if (o.error2 > -o.deltay)
		{
			o.error -= o.deltay;
			p.x1 += o.signx;
		}
		if (o.error2 < o.deltax)
		{
			o.error += o.deltax;
			p.y1 += o.signy;
		}
		mew.color = rgb_to_hex(mew.color_change, mew.steps);
	}
}

extern void		bres(t_pos p, t_s *e)
{
	t_bres	o;
	t_help	mew;

	o.deltax = abs(p.x2 - p.x1);
	o.deltay = abs(p.y2 - p.y1);
	o.error = o.deltax - o.deltay;
	if (p.x1 < p.x2)
		o.signx = 1;
	else if (p.x1 > p.x2)
		o.signx = -1;
	if (p.y1 < p.y2)
		o.signy = 1;
	else if (p.y1 > p.y2)
		o.signy = -1;
	mew.line = line_len(p, o);
	mew.steps = hex_to_rgb(e->color, e->next_color, mew.line);
	mew.color = rgb_to_hex(e->color, mew.steps);
	drawing(p, mew, o, e);
	free(mew.steps);
}
