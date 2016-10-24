/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
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
	if (environ)
	{
		*env = build_env(environ);
		return (1);
	}
	return (-1);
}

int				ft_setenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist		*ptr;

	ptr = env;
	if (memory->var && data->index == 1)
		return (export_var(&env, memory->var));
	else if (memory->var && data->index >= 1)
		return (export_var0(&env, memory->var, data->option, data->index));
	else
		return (32);
	return (0);
}
