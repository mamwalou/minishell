/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 14:19:40 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/01 18:50:01 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include <stdio.h>

static int		ft_stspchr(char *s, char c)
{
	int		i;

	i = 1;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static int		find_occur(const char *s, char c)
{
	int			ret;

	ret = 0;
	while (*s)
	{
		if (*s == c)
		{
			ret++;
			while (*s == c)
				*s++;
		}
		s++;
	}
	return(ret);
}

char			*split(char *s, int pos,char c)
{
	int len;
	char *dst;

	len = ft_stspchr(s, c);
	dst = ft_strndup(s, pos, len - 1);
	return (dst);
}

int				ft_strsplit(char ***dst,char const *s, char c)
{
	int pos;
	int i;
	int len;


	if (!*s)
		return (0);
	len = find_occur(s, c) + 1;
	*dst = malloc(sizeof(char*) * (len + 1));
	i = 0;
	pos = 0;
	while (i < len)
	{
		dst[0][i] = split((char*)s ,pos, c);
		s = ft_strrchr(s, c);
		i++;
	}
	dst[0][i] = NULL;
	return (len);
}
