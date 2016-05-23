/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:42:49 by salomon           #+#    #+#             */
/*   Updated: 2016/05/18 23:05:34 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/Includes/libft.h"
# include <unistd.h>

typedef struct				s_data
{
	char					*cmd;
	char					*opt;
	char					operation;
	int						index;
	struct s_data 			*left;
	struct s_data			*right;
}							t_data;


int			my_setenv(char ***environ, const char *env, const char *value);
char		*search_env(char **environ, const char *value);
void 		exec_cmd(char **environ, char *line);
int			do_bulltin(char *line, char **environ);
void 		parser(char **environ, char *line, t_data *data);
#endif
