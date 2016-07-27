/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:16:15 by sbeline           #+#    #+#             */
/*   Updated: 2014/11/15 16:10:16 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (i < n && d[i] != (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	if (i == n)
		return (NULL);
	if (d[i] == (unsigned char)c)
	{
		s[i] = d[i];
		i++;
	}
	return ((void*)(s + i));
}
