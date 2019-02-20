/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:23:16 by kvilna            #+#    #+#             */
/*   Updated: 2017/10/30 17:23:18 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	int			j;
	int			k;
	char		*c;

	i = 0;
	if (little[0] == '\0' || big == little)
		return ((char*)big);
	while (big[i] != '\0' && i < len)
	{
		k = i;
		j = 0;
		if (big[i] == little[j] && (c = (char*)&big[i]))
		{
			while (little[j] != '\0' && big[i] == little[j] && i < len)
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
