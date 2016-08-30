/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:42:49 by salomon           #+#    #+#             */
/*   Updated: 2016/08/30 23:22:35 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/Includes/libft.h"
# include "termcaps/termcaps.h"
# include <unistd.h>
# define NB_BUILT 5

typedef struct				s_data
{
	int						index;
	char					*cmd;
	char					**option;
	char					*operation;
	struct s_data 			*left;
	struct s_data			*right;
}							t_data;

typedef struct				s_memory
{
	char					*VAR;
}							t_memory;

typedef struct				s_built
{
	char					*str;
	int						(*f)(t_data *, t_llist *, t_memory *);
}							t_built;

					/*EROOR*/
void		ft_print_error(char *error, const char *str);
void		manage_error(int code_err, t_data *data, t_llist *env);

					/*builltin*/
int			ft_variable(t_data *data, t_llist *env, t_memory *memory);
int			ft_cd(t_data *data, t_llist *env, t_memory *memory);
int			ft_env(t_data *data, t_llist *env, t_memory *memory);
int			ft_unsetenv(t_data *data, t_llist *env, t_memory *memory);
int			ft_setenv(t_data *data, t_llist *env, t_memory *memory);
int			my_setenv(t_llist **env,char **environ, const char *value);
char		**my_env(t_llist *env);

					/*exect_it*/
void 		exec_cmd(t_memory *memory,t_llist *env, char *line);

					/*parser*/
int			parser_data(t_llist *env, char **line, t_data **data, t_memory **memory);
t_data		*init_data(t_llist *env, char *line);
char		*search_env(t_llist *env, const char *value);
void 		free_d(char **dtab, int lenght);
char		**init_option(char *opt, char **save);

					/*lexer*/
int			ctrl_var(char *line);
int			my_ctrl(int test);
char		*is_bulltin(char *cmd);
char		*bin_checkout(char *line, t_llist *env);
int			operator_filters(char *line);

					/*memory*/
int			define_variable(t_memory *memory, char *line);
void		init_memory(t_memory *memory);

#endif
