/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:10:34 by salomon           #+#    #+#             */
/*   Updated: 2016/07/27 18:32:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

char		*real_push(char *str, char c)
{
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	tmp = (char*)ft_memalloc(len + 2);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = 0;
	return (tmp);
}

char		*push_line(char c, char *line)
{
	char	*ret;

	if (line == NULL)
	{
		ret = (char*)ft_memalloc(1);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	else
		return (real_push(line, c));
	return (NULL);
}

char		*depushline(char *line)
{
	int 	len;
	int		i;

	len = 0;
	len = ft_strlen(line);
	if (len > 0)
	{
		char *ret;

		ret = (char*)ft_memalloc(len);
		i = 0;
		while (i < len - 1)
		{
			ret[i] = line[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
