/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:17:53 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:43:36 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (unsigned char*)malloc(sizeof(*str) * n);
	ft_memcpy(str, s2, n);
	ft_memcpy(s1, str, n);
	free(str);
	return (s1);
}
