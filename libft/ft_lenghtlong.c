/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:20 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/01 15:18:03 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#define LONG_LONG_MIN 9223372036854775807

int			ft_lenghtlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
		return (20);
	if (ll < 0)
	{
		ret++;
		ll *= -1;
	}
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
