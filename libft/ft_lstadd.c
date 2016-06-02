/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:38:39 by sbeline           #+#    #+#             */
/*   Updated: 2015/10/02 20:23:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void		ft_lstadd(t_llist **alst, t_llist *n)
{
	t_llist *ptr;

	ptr = *alst;
	if (ptr == NULL)
		*alst = n;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = n;
	}
}
