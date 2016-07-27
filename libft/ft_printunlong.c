/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:30:26 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:30:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			ft_printunlong(unsigned long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll >= 10)
	{
		ft_printunlong(ll / 10);
		ft_printunlong(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}
