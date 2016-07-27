/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:22:39 by sbeline           #+#    #+#             */
/*   Updated: 2015/01/10 02:37:36 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

size_t		ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	if (str == NULL)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}
