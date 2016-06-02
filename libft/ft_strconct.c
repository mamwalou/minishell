/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:08:01 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:08:02 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*strconct(char *s1, char *s2, const char *obj)
{
	char *tmp;
	char *ret;

	tmp = ft_strcatdup(s1, obj);
	ret = ft_strcatdup(tmp, s2);
	return (ret);
}
