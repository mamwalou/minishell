/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:42:49 by salomon           #+#    #+#             */
/*   Updated: 2016/07/27 19:18:41 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/Includes/libft.h"
# include "termcaps/termcaps.h"
# include <unistd.h>
# define NB_BUILT 4

typedef struct				s_data
{
	int						index;
	char					*cmd;
	char					**option;
	char					*operation;
	struct s_data 			*left;
	struct s_data			*right;
}							t_data;

typedef struct				s_built
{
	char					*str;
	int						(*f)(t_data *, t_llist *);
}							t_built;

void		ft_print_error(char *error, const char *str);
int			ft_cd(t_data *data, t_llist *env);
int			ft_env(t_data *data, t_llist *env);
int			ft_unsetenv(t_data *data, t_llist *env);
int			ft_setenv(t_data *data, t_llist *env);

					/*builltin*/
int			my_setenv(t_llist **env,char **environ, const char *value);
char		**my_env(t_llist *env);
					/*exect_it*/
void 		exec_cmd(t_llist *env, char *line);

					/*parser*/
int			parser_data(t_llist *env, char **line, t_data **data);
t_data		*init_data(t_llist *env, char *line);
char		*search_env(t_llist *env, const char *value);
void 		free_d(char **dtab, int lenght);

			/*lexer*/
int			my_ctrl(int test);

char		**push_option(char *opt, char **save);
char		*is_bulltin(char *cmd);
char		*bin_checkout(char *line, t_llist *env);
int			data_filters(char *line);

#endif
