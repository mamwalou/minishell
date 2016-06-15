/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:41:24 by salomon           #+#    #+#             */
/*   Updated: 2016/06/14 23:16:59 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void				ft_print_error(char *error, const char *str)
{
	ft_putstr(error);
	ft_putendl(str);
}

void 			prompt(t_llist *env)
{
	ft_putstr(ft_strjoin("\033[1;31m", search_env(env, "USERNAME=")));
	ft_putstr("\033[0m:");
	ft_putstr(ft_strjoin("\033[1;69m", search_env(env, "PWD=")));
	ft_putstr("\033[0m:");
	ft_putstr(" $>");
}

int					main(int argc, char **argv, char **environ)
{
	t_llist		*env;
	char		*cmd;

	env = NULL;
	my_setenv(&env ,environ, NULL);
	prompt(env);
	while  (get_next_line(0, &cmd) == 1 && ft_strcmp(cmd, "exit") != 0)
	{
		exec_cmd(env, cmd);
		my_setenv(&env, environ, NULL);
		prompt(env);
	}
	return (0);
}
