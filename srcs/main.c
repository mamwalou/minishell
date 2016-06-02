/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:41:24 by salomon           #+#    #+#             */
/*   Updated: 2016/06/01 18:49:53 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void				ft_print_error(const char *str)
{
	ft_putendl(str);
	exit(1);
}

void 			prompt(char **environ)
{
	char *usr;

	if ((usr = search_env(environ, "USERNAME=")) == NULL)
		exit(1);
	ft_putstr(usr);
	ft_putstr("$>");
}

int					main(int argc, char **argv, char **environ)
{
	char		*cmd;

	/*if (*environ == NULL)
	{
		if ((access("/usr/bin", X_OK)) != -1)
		{
			if ((set_env(&environ, "PATH", "/usr/bin")) == -1)
				ft_print_error("Could'nt allocated");
		}
	}*/
	prompt(environ);
	while  (get_next_line(0, &cmd) == 1 && ft_strcmp(cmd, "exit") != 0)
	{
		exec_cmd(environ, cmd);
		prompt(environ);
	}
	return (0);
}
