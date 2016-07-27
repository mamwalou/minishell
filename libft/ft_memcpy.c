/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:03:05 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:42:35 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*c1;
	char	*c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	if (n == 0 || s1 == s2)
		return (s1);
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (s1);
}
