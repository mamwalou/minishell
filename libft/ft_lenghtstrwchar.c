/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtstrwchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:29 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:30 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_lenghstrwchar(const wchar_t *wc)
{
	int count;

	count = 0;
	while (*wc)
		count += ft_lenghtwchar(*wc++);
	return (count);
}
