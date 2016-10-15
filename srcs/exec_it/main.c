/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:41:24 by salomon           #+#    #+#             */
/*   Updated: 2016/10/11 12:05:53 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/termcaps/termcaps.h"
#include <time.h>

int					prompt(t_llist *env)
{
	int				lenght_prompt;

	lenght_prompt = 0;
	if ((search_env(env, "USER=")))
	{
		ft_putstr(ft_strjoin("\033[1;31m", search_env(env, "USER=")));
		lenght_prompt = ft_strlen(search_env(env, "USER="));
		ft_putstr("\033[0m:");
	}
	if ((search_env(env, "PWD=")))
	{
		ft_putstr(ft_strjoin("\033[1;69m", search_env(env, "PWD=")));
		ft_putstr("\033[0m:");
		lenght_prompt += ft_strlen(search_env(env, "PWD="));
	}
	ft_putstr(" $>");
	return (lenght_prompt + 3);
}

int					main(int argc, char **argv, char **environ)
{
	t_memory		memory;
	t_llist			*env;
	t_window		win;
	int				ctrl;

	ctrl = 0;
	env = NULL;
	win.set = 0;
	memory.var = NULL;
	while (ctrl == 0)
	{
		my_setenv(&env, environ, NULL);
		memory.line = NULL;
		if ((termcaps(env, &memory.line, prompt(env), &win)) == -1)
			return (-1);
		ft_putchar('\n');
		if (memory.line)
			ctrl = exec_cmd(&memory, env);
		free(memory.line);
	}
	ft_lstdel(&env, ft_bzero);
	return (0);
}
