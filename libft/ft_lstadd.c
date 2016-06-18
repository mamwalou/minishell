/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:38:39 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/08 00:44:10 by salomon          ###   ########.fr       */
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
		ptr->next->maillon_nb = ptr->maillon_nb + 1;
	}
}
