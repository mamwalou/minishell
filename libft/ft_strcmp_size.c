/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:07:57 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:11:26 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_strcmp_size(off_t s1, off_t s2, int reverse)
{
	if (reverse)
	{
		if (s1 < s2)
			return (-1);
		else if (s1 > s2)
			return (1);
		return(0);
	}
	if (s1 < s2)
		return (1);
	else if (s1 > s2)
		return (-1);
	return (0);
}
