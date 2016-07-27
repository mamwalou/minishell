/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 14:12:26 by sbeline           #+#    #+#             */
/*   Updated: 2015/10/21 15:59:53 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static void		read_list(t_llist *l)
{
	t_llist		*ptr;

	ptr = l;
	while (ptr != NULL)
	{
		ft_putstr(ptr->content);
		ft_putstr("\n");
		ptr = ptr->next;
	}
}

static void		merge(t_llist **l, t_llist *nvl_elm)
{
	t_llist		*p;
	t_llist		*tmp;

	p = *l;
	if (p == NULL)
		*l = nvl_elm;
	else
	{
		while (p->next != NULL)
		{
			if ((ft_stralpha(p->next->content, nvl_elm->content)) == 1)
			{
				tmp = p->next;
				p->next = nvl_elm;
				nvl_elm->next = tmp;
				return ;
			}
			p = p->next;
		}
		p->next = nvl_elm;
	}
}
static void		trifusion(t_llist *alst)
{
	t_llist		*ptr;
	t_llist		*l1;
	t_llist		*l2;
	t_llist		*tmp;

	l1 = NULL;
	l2 = NULL;
	ptr = alst;
	if (alst->next == NULL)
		return ;
	while (ptr != NULL)
	{
		tmp = ft_lstnew(ptr->content, ptr->content_size);
		if ((ptr->maillon_nb % 2) == 1)
			merge(&l1, tmp);
		else
			merge(&l2, tmp);
		ptr = ptr->next;
	}
		read_list(l1);
		ft_putstr("<--->");
		read_list(l2);
}
void		ft_lsttri(t_llist **alst, int opt)
{
	if (opt == 1)
	{
		trifusion(*alst);
	}
}
