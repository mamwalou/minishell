/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:08:22 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/19 00:35:38 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strndup(char *s, int begin, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret  = (char*)malloc(sizeof(char) * (end - begin) + 1)))
		return(NULL);
	while (begin < end)
	{
		ret[i] = s[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
	return (ret);
}
