/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:08:17 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:08:18 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int					ft_strnb(void *var)
{
	int				size;
	int				nb;

	size = 1;
	nb = *(int*)var;
	while (nb >= 10)
	{
		nb = nb / 10;
		size = size + 1;
	}
	return (size);
}
