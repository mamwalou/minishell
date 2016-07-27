/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:10:20 by sbeline           #+#    #+#             */
/*   Updated: 2015/07/22 16:20:04 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	l = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	else
		return (NULL);
	return (s2);
}
