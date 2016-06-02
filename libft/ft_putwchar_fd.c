/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:07:21 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:07:23 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void 	ft_putwchar_fd(wchar_t wc, int fd)
{
	if (wc < (1 << 7))
		ft_putchar_fd((char)wc, fd);
	else if (wc < (1 << 11))
	{
		ft_putchar_fd((char)((wc >> 6)|0xC0), fd);
		ft_putchar_fd((char)((wc & 0x3F)|0x80), fd);
	}
	else if (wc < (1 << 16))
	{
		ft_putchar_fd((char)((wc >>12) | 0xE0), fd);
		ft_putchar_fd((char)(((wc >> 6) & 0x3F) | 0x80), fd);
		ft_putchar_fd((char)((wc & 0x3F)| 0x80), fd);
	}
	else if (wc < (1 << 21))
	{
		ft_putchar_fd((char)((wc >> 18) | 0xE0), fd);
		ft_putchar_fd((char)(((wc >> 12) & 0x3F) | 0x80), fd);
		ft_putchar_fd((char)(((wc >> 6) & 0x3F) | 0x80), fd);
		ft_putchar_fd((char)((wc & 0x3F)| 0x80), fd);
	}
}
