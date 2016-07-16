/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:42:49 by salomon           #+#    #+#             */
/*   Updated: 2016/07/16 17:55:33 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/Includes/libft.h"
# include "termcaps/termcaps.h"
# include <unistd.h>

typedef struct				s_data
{
	int						index;
	char					*cmd;
	char					**option;
	char					*operation;
	struct s_data 			*left;
	struct s_data			*right;
}							t_data;

void		ft_print_error(char *error, const char *str);
					/*builltin*/
int			my_setenv(t_llist **env,char **environ, const char *value);
char		**my_env(t_llist *env);
					/*exect_it*/
void 		exec_cmd(t_llist *env, char *line);

					/*lexer parser DATA*/
int			parser_data(t_llist *env, char **line, t_data **data);
t_data		*init_data(t_llist *env, char *line);
char		*search_env(t_llist *env, const char *value);
void 		free_d(char **dtab, int lenght);

char		**push_option(char *opt, char **save);
char		*is_bulltin(char *cmd);
char		*bin_checkout(char *line, t_llist *env);
int			data_filters(char *line);

#endif
