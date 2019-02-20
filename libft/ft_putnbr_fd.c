/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 12:30:09 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/31 12:30:10 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	k;
	long long	j;

	k = n;
	if (k < 0)
	{
		k = -k;
		write(fd, "-", 1);
	}
	if (k >= 10)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	else
	{
		j = k + '0';
		write(fd, &j, 1);
	}
}
