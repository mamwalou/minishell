/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:18:13 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:43:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	tmp = (unsigned char*)s;
	if (n <= 0)
		return (s);
	while (count < n)
	{
		tmp[count] = c;
		count++;
	}
	return (s);
}
