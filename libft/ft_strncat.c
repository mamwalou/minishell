/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:34:40 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:47:24 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	while (s2[i] != '\0' && i < n)
	{
		s1[len] = s2[i];
		i++;
		len++;
	}
	s1[len] = '\0';
	return (s1);
}
