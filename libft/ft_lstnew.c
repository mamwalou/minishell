/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:23:35 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/08 00:44:13 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_lstnew(void const *content, size_t content_size)
{
	t_llist	*ptr;
	void	*cnt;

	cnt = (void*)ft_memalloc(content_size + 1);
	cnt = ft_memcpy(cnt, content, content_size);
	ptr = (t_llist*)ft_memalloc(sizeof(t_llist));
	ptr->content_size = content_size;
	ptr->content = cnt;
	ptr->maillon_nb = 0;
	ptr->next = NULL;
	return (ptr);
}
