/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:46:28 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/14 18:46:32 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_strmove(char **s, int pos)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*s) - pos + 1, (*s + pos));
	ft_strdel(s);
	*s = tmp;
}
