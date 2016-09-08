/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 03:13:02 by salomon           #+#    #+#             */
/*   Updated: 2016/09/08 14:26:54 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static const t_built	g_builtin[NB_BUILT] =
{
	{"cd", ft_cd},
	{"env", ft_env},
	{"export", ft_setenv},
	{"unset", ft_unsetenv},
	{"var", ft_variable},
};

void					exect_it(t_data *data, t_llist *env)
{
	pid_t				father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return ;
	}
	if (father == 0)
		execve(data->cmd, data->option, NULL);
}

int						exec_parser(t_data *data, t_llist *env, t_memory *mem)
{
	int		i;

	i = 0;
	if ((is_bulltin(data->cmd)) != NULL && ft_strcmp(data->cmd, "exit"))
	{
		while (i < NB_BUILT)
		{
			if (!ft_strcmp(g_builtin[i].str, data->cmd))
				return (g_builtin[i].f(data, env, mem));
			i++;
		}
	}
	else if (!ft_strcmp(data->cmd, "exit"))
		return (42);
	else
		exect_it(data, env);
	return (0);
}

int						exec_cmd(t_memory *memory, t_llist *env, char *line)
{
	t_data				*data;
	char				**pline;
	int					lenght;
	int					error;

	error = 0;
	data = NULL;
	if ((lenght = ft_strsplit(&pline, line, generate(9, 32, 3))) == -1)
		return (0);
	if (lenght > 0)
	{
		error = parser_data(env, pline, &data, &memory);
		if (error < 0)
		{
			ft_putstr(line);
			manage_error(error, data, env);
		}
		else if (error < 5)
		{
			if ((error = exec_parser(data, env, memory)) != 0)
				return (manage_error(error, data, env));
		}
	}
	free_d(pline, lenght);
	return (0);
}
