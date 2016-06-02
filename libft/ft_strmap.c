/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:15:28 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:47:08 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((str_res = ft_strdup((char*)s)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_res[i] = f(s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
