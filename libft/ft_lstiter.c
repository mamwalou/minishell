/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:47:17 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/14 13:48:54 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_lstiter(t_llist *lst, void (*f)(t_llist *elem))
{
	if (lst && f)
	{
		ft_lstiter(lst->next, f);
		(*f)(lst);
	}
}
