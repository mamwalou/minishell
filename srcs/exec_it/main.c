/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:41:24 by salomon           #+#    #+#             */
/*   Updated: 2016/08/30 19:39:30 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int 			prompt(t_llist *env)
{
	int				lenght_prompt;

	lenght_prompt = 0;
	ft_putstr(ft_strjoin("\033[1;31m", search_env(env, "USER=")));
	lenght_prompt = ft_strlen(search_env(env, "USER="));
	ft_putstr("\033[0m:");
	ft_putstr(ft_strjoin("\033[1;69m", search_env(env, "PWD=")));
	ft_putstr("\033[0m:");
	lenght_prompt += ft_strlen(search_env(env, "PWD="));
	ft_putstr(" $>");
	return (lenght_prompt + 3);
}

int					main(int argc, char **argv, char **environ)
{
	t_memory		memory;
	t_llist			*env;
	char			*line;
	int				ctrl;
	int				lenght_prompt;

	ctrl = 0;
	env = NULL;
	init_memory(&memory);
	while (ctrl == 0)
	{
		line = NULL;
		my_setenv(&env, environ, NULL);
		lenght_prompt = prompt(env);
		if ((termcaps(env, &line, lenght_prompt)) == -1)
			return (-1);
		if (line)
			exec_cmd(&memory, env, line);
		free(line);
	}
	return (0);
}
