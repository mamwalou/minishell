/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:10:13 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/14 14:53:05 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_lstmap(t_llist *lst, t_llist *(*f)(t_llist *elem))
{
	t_llist	*new_list;
	t_llist	*begin;
	t_llist	*tmp;

	if (f == NULL && lst == NULL)
		return (NULL);
	tmp = f(lst);
	new_list = ft_lstnew(tmp->content, tmp->content_size);
	if (new_list == NULL)
		return (NULL);
	begin = new_list;
	while (lst->next != NULL)
	{
		tmp = f(lst->next);
		new_list->next = ft_lstnew(tmp->content, tmp->content_size);
		if (new_list->next == NULL)
		{
			ft_lstdel(&begin, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		new_list = new_list->next;
	}
	return (begin);
}
