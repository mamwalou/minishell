/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 00:48:03 by salomon           #+#    #+#             */
/*   Updated: 2016/09/07 00:12:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ctrl_var(char *line)
{
	int i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	if (line[i] == '=' && i > 0)
		return (0);
	return (1);
}

int		operator_filters(char *line)
{
	char		*tableau[8];
	int			i;

	tableau[0] = ">";
	tableau[1] = "<";
	tableau[2] = ">&";
	tableau[3] = ">!";
	tableau[4] = ">!&";
	tableau[5] = "|";
	tableau[6] = ">>";
	tableau[7] = ">>&";
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp(tableau[i], line))
			return (1);
		i++;
	}
	return (-1);
}

int			my_ctrl(int test)
{
	if (test == '-'
		|| test == ';'
		|| test == '<'
		|| test == '>'
	 	|| test == '&'
		|| test == '='
		|| test == '!')
		return (1);
	return (0);
}

char			*is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unsetenv") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "var") == 0)
		return (cmd);
	return (NULL);
}

char			*bin_checkout(char *line, t_llist *env)
{
	char		**bin;
	char		*cpy;
	int			lenght_bin;
	int			i;
	int			tableau[]= {58, 0};

	i = 0;
	cpy = NULL;
	lenght_bin = ft_strsplit(&bin , search_env(env, "PATH"), tableau);
	while (i < lenght_bin)
	{
		if ((access(ft_strtrijoin(bin[i], "/", line), X_OK)) == 0)
		{
			cpy = (ft_strtrijoin(bin[i], "/", line));
			free_d(bin, lenght_bin);
			return (cpy);
		}
		i++;
	}
	free_d(bin, lenght_bin);
	return(NULL);
}
