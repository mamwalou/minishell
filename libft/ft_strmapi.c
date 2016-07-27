/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:15:28 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/07 12:47:16 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((str_res = ft_strdup((char*)s)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str_res[i] = f(i, s[i]);
		i++;
	}
	return (str_res);
}
