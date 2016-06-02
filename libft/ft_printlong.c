/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:30:19 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:30:21 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			ft_printlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (ll < 0)
	{
		ft_putchar('-');
		ll = -ll;
	}
	if (ll >= 10)
	{
		ft_printlong(ll / 10);
		ft_printlong(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}
