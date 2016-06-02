/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrijoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 17:23:18 by salomon           #+#    #+#             */
/*   Updated: 2016/05/18 17:26:59 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"


char		*ft_strtrijoin(const char *s1, const char *s2, const char *s3)
{
	char *tmp;
	char *ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	ret = ft_strjoin(tmp, s3);
	return (ret);
}
