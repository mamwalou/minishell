/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtunint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:34 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:35 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenghtunint(unsigned int nb)
{
	size_t	ret;

	ret = 1;
	if (nb == UINT_MAX)
		return (10);
	while ((nb /= 10) > 0)
		ret++;
	return (ret);
}
