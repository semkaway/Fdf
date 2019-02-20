/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 08:23:36 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/06 08:24:36 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp1;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			tmp1 = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp1;
		}
		*alst = NULL;
	}
}
