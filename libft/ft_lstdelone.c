/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 13:30:45 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/14 14:00:03 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_lstdelone(t_llist **alst, void (*del)(void*, size_t))
{
	if (*alst)
		(*del)((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
