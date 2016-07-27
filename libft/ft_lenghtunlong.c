/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtunlong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:39 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:41 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenghtunlong(unsigned long long ll)
{
	size_t	ret;

	ret = 1;
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
