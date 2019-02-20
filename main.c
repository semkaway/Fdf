/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:00:30 by kvilna            #+#    #+#             */
/*   Updated: 2017/12/11 14:00:34 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		exit_func(int keyhook, t_s *e)
{
	if (keyhook == 53)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	if (keyhook == 69)
		e->k += 2;
	if (keyhook == 78)
		e->k -= 2;
	if (keyhook == 123)
		e->d2 -= 10;
	if (keyhook == 124)
		e->d2 += 10;
	if (keyhook == 125)
		e->d += 10;
	if (keyhook == 126)
		e->d -= 10;
	draw_mult_lines(e);
	return (0);
}

extern void		file_validation(t_s *e)
{
	int		i;
	int		j;

	row_validation(e);
	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			if (ft_strchr(e->map[i], ' ') == NULL)
				usage_message("ACHTUNG! Invalid file", 2, 42);
			if (e->map[i][j] == ' ' && e->map[i][j + 1] != ' ')
				if (ft_isdigit(e->map[i][j + 1]) == 0)
					if (e->map[i][j + 1] != '-' && e->map[i][j + 1] != '\0')
						usage_message("ACHTUNG! Invalid file", 2, 42);
			j++;
		}
		i++;
	}
}

extern int		usage_message(char *line, int fd, int bye)
{
	if (ft_strcmp(line, "wrong color") == 0)
	{
		ft_putendl("I don't know the name of the color you entered :(");
		ft_putendl("Please try:");
		ft_putendl("- red\n- green\n- blue\n- nature\n- default\n- none");
		ft_putendl("- enter the hexadecimal color code starting with \"0x\"");
	}
	else
		ft_putendl_fd(line, fd);
	exit(bye);
}

static	void	mlxfunc(t_s *e)
{
	if ((e->c >= 45 && e->c < 100) || (e->r >= 45 && e->c < 100)
		|| (e->r > e->c))
	{
		e->height = 650;
		e->width = 650;
		e->k = 22;
	}
	if (e->c >= 100 || e->r >= 100)
		e->k = 20;
	if (e->c >= 300 || e->r >= 300)
	{
		e->height = 250;
		e->width = 400;
		e->measure = 300;
		e->k = 44;
	}
	while (e->measure <= e->r && e->measure <= e->c)
	{
		e->height += 50;
		e->width += 50;
		e->measure += 10;
		e->k -= 2;
	}
	if (e->k <= 0)
		e->k = 4;
}

int				main(int argc, char **argv)
{
	t_s		e;

	if (argc != 3 && argc != 2)
		usage_message("usage: fdf input_file color", 2, 42);
	e.an = -30;
	e.measure = 0;
	e.height = 500;
	e.width = 500;
	e.k = 25;
	e.color = 0xffffff;
	if (argc == 3)
		e.user_color = ft_strdup(argv[2]);
	else if (argc == 2)
		e.user_color = ft_strdup("none");
	read_file(argv[1], &e);
	mlxfunc(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.width, e.height, "FdF");
	position(&e);
	draw_mult_lines(&e);
	mlx_key_hook(e.win, exit_func, &e);
	mlx_loop(e.mlx);
	free_func(&e);
	return (0);
}
