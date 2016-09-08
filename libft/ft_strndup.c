/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:08:22 by sbeline           #+#    #+#             */
/*   Updated: 2016/09/08 15:55:56 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strndup(char *s, int begin, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (end - begin) + 1)))
		return (NULL);
	while (begin < end)
	{
		ret[i] = s[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
	return (ret);
}
