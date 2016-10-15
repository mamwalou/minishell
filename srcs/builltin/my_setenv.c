/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 00:45:13 by salomon           #+#    #+#             */
/*   Updated: 2016/10/15 17:23:19 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_llist			*build_env(char **environ)
{
	t_llist		*ret;

	ret = NULL;
	while (*environ)
	{
		ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
	}
	return (ret);
}

int				my_setenv(t_llist **env, char **environ, const char *value)
{
	char		*buf;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	if (!value && !*env)
	{
		*env = build_env(environ);
		return (1);
	}
	if ((search_env(*env, "PWD=")) == NULL)
	{
		ft_lstadd(env, ft_lstnew(ft_strjoin("PWD=", buf),
					ft_strlen(ft_strjoin("PWD=", buf))));
	}
	if (!value && *env)
		return (0);
	else
		ft_lstadd(env, ft_lstnew(value, ft_strlen(value)));
	return (-1);
}


int				ft_setenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist *ptr;

	ptr = env;
	if (memory->var && data->index == 1)
		return (export_var(&env, memory->var));
	else if (memory->var && data->index >= 1)
		return (export_var0(&env, memory->var, data->option, data->index));
	else
		return (32);
	return (0);
}
