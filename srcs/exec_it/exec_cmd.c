/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 03:13:02 by salomon           #+#    #+#             */
/*   Updated: 2016/08/19 04:11:06 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static const t_built	g_builtin[NB_BUILT] =
{
	{"cd", ft_cd},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
};

void 					exect_it(t_data *data, t_llist *env)
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

int			exec_parser(t_data *data, t_llist *env)
{
	int		i;

	i = 0;
	if ((is_bulltin(data->cmd)) != NULL)
	{
		while (g_builtin[i].str)
		{
			if (!ft_strcmp(g_builtin[i].str, data->cmd))
				return (g_builtin[i].f(data, env));
			i++;
		}
	}
	else
		exect_it(data, env);
	return (1);
}

void 		exec_cmd(t_llist *env, char *line)
{
	t_data	*data;
	char	**pline;
	int		lenght;
	int 	tableau[3] = {9, 32, 0};

	data = NULL;
	lenght = ft_strsplit(&pline, line, tableau);
	if (lenght > 0)
	{
		if ((parser_data(env, pline, &data)) == -1)
			ft_print_error(pline[0], ": command not found");
		else
			exec_parser(data, env);
	}
	free_d(pline, lenght);
}
