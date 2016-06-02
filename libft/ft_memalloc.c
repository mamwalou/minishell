/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:15:50 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:41:39 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!size)
		return (NULL);
	if ((ptr = (void *)malloc(sizeof(void) * size)) == NULL)
		return (NULL);
	ft_bzero((char *)ptr, size + 1);
	return (ptr);
}
