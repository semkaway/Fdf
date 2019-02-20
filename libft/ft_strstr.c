/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:15:48 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 15:15:51 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int			i;
	int			j;
	int			k;
	char		*c;

	i = 0;
	if (little[0] == '\0' || big == little)
		return ((char*)big);
	while (big[i] != '\0')
	{
		k = i;
		j = 0;
		if (big[i] == little[j] && (c = (char*)&big[i]))
		{
			while (little[j] != '\0' && big[i] == little[j])
			{
				if (little[j + 1] == '\0' && big[i] == little[j])
					return (c);
				j++;
				i++;
			}
		}
		i = k + 1;
	}
	return (NULL);
}
