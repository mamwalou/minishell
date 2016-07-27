/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:17:03 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:42:25 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t num)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (s1 == s2 || num == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (num--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		if (num)
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
