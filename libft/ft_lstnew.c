/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:23:35 by sbeline           #+#    #+#             */
/*   Updated: 2015/10/01 16:44:21 by sbeline          ###   ########.fr       */
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
	ptr->next = NULL;
	return (ptr);
}
