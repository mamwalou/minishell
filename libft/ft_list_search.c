/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:27:00 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:58 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_list_search(t_llist *e, const char *str)
{
	while (((ft_strcmp(e->content, str)) && (e->next != NULL)))
		e = e->next;
	if (e->content == NULL)
		return (NULL);
	return (e->content);
}
