/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:37:55 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/11 10:45:32 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char		*ft_chrstr(char *str, char *find)
{
	while (*str && *find && *find == *str)
	{
		find++;
		str++;
	}
	return ((char*)str);
}
