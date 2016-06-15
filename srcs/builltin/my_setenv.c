/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 00:45:13 by salomon           #+#    #+#             */
/*   Updated: 2016/06/08 00:44:18 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_llist			*build_env(char **environ)
{
	t_llist *ret;

	ret = NULL;
	while (*environ)
	{
		ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
	}
	return (ret);
}

int		my_setenv(t_llist **env,char **environ, const char *value)
{
	if (!value && !*env)
	{
		*env = build_env(environ);
		return (1);
	}
	if (!value && *env)
		return (0);
	else
	{
		ft_lstadd(env, ft_lstnew(value, ft_strlen(value)));
	}
	return (-1);
}
