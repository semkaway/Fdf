/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:28:05 by kvilna            #+#    #+#             */
/*   Updated: 2017/12/14 12:28:07 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

extern void		row_validation(t_s *e)
{
	int		i;
	int		k;
	int		k_mem;

	i = 1;
	k_mem = ft_count_words(e->map[0], ' ');
	while (e->map[i])
	{
		k = ft_count_words(e->map[i], ' ');
		if (k != k_mem)
			usage_message("ACHTUNG! Invalid file", 2, 42);
		i++;
	}
}

static void		color_validation(char **map, int i, int j, t_s *e)
{
	char	hex[13];
	int		a;

	ft_strcpy(hex, "aAbBcCdDeEfF");
	e->str_color = ft_strnew(6);
	a = 0;
	while (ft_isdigit(map[i][j]) == 0 && ft_strchr(hex, map[i][j]) == 0)
		j++;
	if (map[i][j] == '0' && map[i][j + 1] == 'x')
		j += 2;
	while (map[i][j] != ' ' && map[i][j] != '\0')
	{
		e->str_color[a] = map[i][j];
		a++;
		j++;
	}
	e->index[i][e->col] = hex_to_dec(e->str_color);
	free(e->str_color);
}

static void		check_for_color(char **map, t_s *e)
{
	int		i;
	int		j;

	e->index = create_color_int_arr(e);
	i = 0;
	e->color_flag = 0;
	while (map[i])
	{
		j = 0;
		e->col = 0;
		while (map[i][j])
		{
			if ((j != 0 && map[i][j] == ' ' && map[i][j + 1] != ' '))
				e->col++;
			if (map[i][j] == ',')
			{
				e->color_flag = 1;
				color_validation(map, i, j, e);
			}
			j++;
		}
		i++;
	}
}

static char		*my_realloc(char *buf, char *line)
{
	char	*copy;
	char	*pew;

	if (buf == NULL)
		buf = ft_strdup("");
	copy = ft_strjoin(buf, line);
	pew = ft_strjoin(copy, "\n");
	free(buf);
	free(copy);
	return (pew);
}

extern void		read_file(char *file_name, t_s *e)
{
	int		fd;
	char	*buf;
	char	*line;

	buf = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		usage_message("Please, enter the name of a valid file", 2, 42);
	while (get_next_line(fd, &line) > 0)
	{
		buf = my_realloc(buf, line);
		free(line);
	}
	free(line);
	close(fd);
	if (buf == NULL)
		usage_message("Oops, empty file :(", 2, 42);
	e->map = ft_strsplit(buf, '\n');
	free(buf);
	file_validation(e);
	e->int_map = create_int_arr(e);
	check_for_color(e->map, e);
	if ((e->color_flag == 0) || (e->color_flag == 1
		&& ft_strcmp(e->user_color, "none") != 0))
		colors(e);
}
