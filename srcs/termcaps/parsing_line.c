/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:10:34 by salomon           #+#    #+#             */
/*   Updated: 2016/09/06 16:17:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

t_llist					*created_path(int *tabulation, t_llist *e)
{
	DIR				*ptr;
	struct dirent 	*fl;
	t_llist			*ret;
	int				lenght;

	ret = 0;
	if ((ptr = opendir(search_env(e, "PWD="))) == NULL)
		exit (1);
	while ((fl = readdir(ptr)) != NULL)
	{
		lenght = ft_strlen(fl->d_name);
		if (fl->d_name[0] != '.')
			ft_lstadd(&ret, ft_lstnew(fl->d_name, lenght));
		if (lenght > *tabulation)
			*tabulation = lenght;
	}
	return (ret);
}

char				*real_push(char *str, char c)
{
	char			*tmp;
	int				len;
	int				i;

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

char				*push_line(char c, char *line, t_window *win)
{
	char			*ret;

	win->lineshell++;
	win->pos[0]++;
	if (line == NULL)
	{
		ret = (char*)ft_memalloc(1);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	else
		return (real_push(line, c));
	return (line);
}

char				*depushline(char *line, t_window *win)
{
	int		i;
	char *ret;

	if ((ret = (char*)ft_memalloc(win->lineshell)) == NULL)
		return (NULL);
	i = 0;
	while (i < win->lineshell)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char				*parsing_term(int code, char *line, t_window *win)
{
	if (code == SPACE)
		return (push_line(' ', line, win));
	else if (code == DELETE)
		return (depushline(line, win));
	return (line);
}
