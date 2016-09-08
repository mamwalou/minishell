/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 00:45:13 by salomon           #+#    #+#             */
/*   Updated: 2016/09/08 14:16:31 by sbeline          ###   ########.fr       */
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
		ft_env(NULL, *env, NULL);
	}
	if (!value && *env)
		return (0);
	else
		ft_lstadd(env, ft_lstnew(value, ft_strlen(value)));
	return (-1);
}

void			export_var(t_llist **env, char *var)
{
	char		*tmp;
	char		*ptr;
	int			i;

	i = 0;
	ptr = var;
	while (var[i])
		i++;
	while ((ptr = ft_strrchr(var, ';')) != NULL)
	{
		ft_lstadd(env, ft_lstnew(var, ptr - var - 1));
		var = ptr;
	}
	if (ptr == NULL)
		ft_lstadd(env, ft_lstnew(var, &var[i] - var));
}

int				ft_setenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist *ptr;

	ptr = env;
	if (memory->var)
		export_var(&env, memory->var);
	else
		return (32);
	return (0);
}
