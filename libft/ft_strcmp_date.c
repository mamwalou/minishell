/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:07:52 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:07:53 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_strcmp_date(time_t t1, time_t t2, int reverse)
{
	if (reverse)
	{
		if (t1 < t2)
			return (-1);
		if (t1 > t2)
			return (1);
		return(0);
	}
	if (t1 < t2)
		return (1);
	if (t1 > t2)
		return (-1);
	return(0);
}
