/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:47:55 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/15 03:09:50 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnew(size_t size, const char *s)
{
	char	*tmp;
	void	*begin;

	if ((tmp = (char*)malloc(sizeof(char) * (size + 1))))
	{
		begin = tmp;
		while (*s && size--)
			*tmp++ = *s++;
		*tmp = '\0';
		return (begin);
	}
	return (NULL);
}
