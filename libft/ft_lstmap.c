/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvilna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 08:26:48 by kvilna            #+#    #+#             */
/*   Updated: 2017/11/06 08:28:28 by kvilna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*it;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(res = (*f)(lst)))
		return (0);
	it = res;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!tmp)
		{
			free(res);
			return (0);
		}
		it->next = tmp;
		it = tmp;
		lst = lst->next;
	}
	it->next = 0;
	return (res);
}
