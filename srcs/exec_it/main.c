/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:41:24 by salomon           #+#    #+#             */
/*   Updated: 2016/07/16 17:55:43 by sbeline          ###   ########.fr       */
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
	ft_putstr(ft_strjoin("\033[1;31m", search_env(env, "USER=")));
	ft_putstr("\033[0m:");
	ft_putstr(ft_strjoin("\033[1;69m", search_env(env, "PWD=")));
	ft_putstr("\033[0m:");
	ft_putstr(" $>");
}

int					main(int argc, char **argv, char **environ)
{
	t_llist		*env;
	char		*line;
	int			ctrl;

	env = NULL;
	line = NULL;
	ctrl = 0;
	while (ctrl == 0)
	{
		my_setenv(&env, environ, NULL);
		prompt(env);
		if ((termcaps(env, &line)) == -1)
			return (-1);
		/*if (get_next_line(0, &line) == 1)
			exec_cmd(env, line);*/

	}
	return (0);
}
