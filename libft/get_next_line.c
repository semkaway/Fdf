/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:39:07 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/23 12:39:53 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void	copy_till_n(char *line, char buf[])
{
	int		i;
	int		j;

	j = ft_strlen(line);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[j] = buf[i];
		i++;
		j++;
	}
	line[j] = '\0';
}

void	update_buf(char buf[], int c)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (buf[0] == '\0')
		return ;
	tmp = (char*)malloc(sizeof(*tmp) * BUFF_SIZE);
	while (buf[i] != (char)c)
		i++;
	i++;
	while (buf[i] != '\0')
	{
		tmp[j] = buf[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	ft_bzero(buf, ft_strlen(buf));
	ft_strncat(buf, tmp, ft_strlen(tmp));
	free(tmp);
}

char	*action(char buf[], int bytes_read, char *line, int fd)
{
	char	*copy;

	while (ft_strchr(buf, '\n') == NULL && bytes_read != 0)
	{
		ft_strncat(line, buf, bytes_read);
		ft_bzero(buf, ft_strlen(buf));
		bytes_read = read(fd, buf, BUFF_SIZE);
		copy = ft_strdup(line);
		free(line);
		line = (char*)malloc(sizeof(char) * ft_strlen(copy) + bytes_read + 1);
		ft_strcpy(line, copy);
		free(copy);
	}
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	int			bytes_read;

	bytes_read = BUFF_SIZE;
	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	*line = NULL;
	if (buf[0] == '\0')
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		if (bytes_read == -1)
			return (-1);
		if (bytes_read < BUFF_SIZE)
			buf[bytes_read] = '\0';
		else
			buf[BUFF_SIZE] = '\0';
	}
	*line = ft_strnew(ft_strlen(buf));
	if (ft_strchr(buf, '\n') == NULL)
		*line = action(buf, bytes_read, *line, fd);
	copy_till_n(*line, buf);
	update_buf(buf, '\n');
	if (ft_strcmp(*line, "\0") == 0 && bytes_read == 0)
		return (0);
	return (1);
}
