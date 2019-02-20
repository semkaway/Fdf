/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_formulas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:53:22 by kvilna            #+#    #+#             */
/*   Updated: 2018/01/05 16:53:24 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**changes by z
*/

extern float	new_pos_x_z(float x, float y, float l)
{
	float	x3;

	l = l * (M_PI / 180);
	x3 = x * cos(l) - y * sin(l);
	return (x3);
}

extern float	new_pos_y_z(float x, float y, float l)
{
	float	y3;

	l = l * (M_PI / 180);
	y3 = x * sin(l) + y * cos(l);
	return (y3);
}

/*
**changes by x
*/

extern float	new_pos_y_x(float z, float y, float l)
{
	float	y3;

	l = l * (M_PI / 180);
	y3 = y * cos(l) + z * sin(l);
	return (y3);
}

extern float	new_pos_z_x(float z, float y, float l)
{
	float	z3;

	l = l * (M_PI / 180);
	z3 = -y * sin(l) + z * cos(l);
	return (z3);
}
