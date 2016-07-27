/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 17:19:36 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/18 17:29:09 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3)
	{
		i = 0;
		while (*s1)
		{
			s3[i++] = *s1;
			s1++;
		}
		while (*s2)
		{
			s3[i++] = *s2;
			s2++;
		}
		s3[i] = '\0';
	}
	return (s3);
}
