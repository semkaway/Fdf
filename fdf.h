/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:53:40 by kvilna            #+#    #+#             */
/*   Updated: 2017/12/11 12:54:02 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	void		*img;
	int			r;
	int			c;
	float		k;
	int			height;
	int			width;
	int			measure;
	float		d;
	float		d2;
	int			**int_map;
	char		**map;
	float		an;
	int			z_max;
	int			z_min;
	int			color;
	int			next_color;
	int			color_flag;
	char		*user_color;
	int			**index;
	char		*str_color;
	int			col;
	int			storage_num;
}				t_s;

typedef struct	s_px
{
	float		r;
	float		g;
	float		b;
}				t_px;

typedef struct	s_pos
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			i;
	int			j;
}				t_pos;

typedef struct	s_bres
{
	int			deltax;
	int			deltay;
	int			error2;
	int			signx;
	int			signy;
	int			error;
}				t_bres;

typedef struct	s_help
{
	float		line;
	int			color_change;
	int			color;
	float		*steps;
}				t_help;

void			bres(t_pos p, t_s *stuff);
void			read_file(char *file_name, t_s *e);
int				usage_message(char *line, int fd, int bye);
int				**create_int_arr(t_s *stuff);
void			draw_mult_lines(t_s *stuff);
void			set_them_free(void **nums, int times);
float			new_pos_x_z(float x, float y, float l);
float			new_pos_y_z(float x, float y, float l);
float			new_pos_y_x(float z, float y, float l);
float			new_pos_z_x(float z, float y, float l);
void			byz(t_s *e, float x[e->r][e->c],
				float y[e->r][e->c], float z[e->r][e->c]);
void			turn_by_x(t_s *e, float y[e->r][e->c], float z[e->r][e->c]);
int				colors(t_s *e);
int				**create_color_int_arr(t_s *e);
int				hex_to_dec(char *s);
int				rgb_to_hex(int start, float *steps);
float			*hex_to_rgb(int start, int end, float line);
void			file_validation(t_s *e);
void			position(t_s *e);
void			start_drawing(t_s *e, float x[e->r][e->c], float y[e->r][e->c]);
void			free_func(t_s *e);
void			row_validation(t_s *e);

#endif
