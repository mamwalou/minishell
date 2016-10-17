/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 02:42:49 by salomon           #+#    #+#             */
/*   Updated: 2016/10/17 15:14:07 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/Includes/libft.h"
# include "termcaps/termcaps.h"
# include <unistd.h>

# define NB_BUILT 7

# define SUCCESS 0
# define ER_CMDNF -1
# define ER_MMR 32
# define ER_PREMMR 33
# define ER_PATHNF 2
# define ER_CDPWDNF 43
# define ER_USEVR 45
# define ER_NTFORD 66
# define ER_EXIT 42
# define OPEN_QUOTE_MODE 2
# define QUOTE_OPT 66

typedef struct		s_data
{
	int				index;
	int				*raw_line;
	char			*cmd;
	char			**option;
	char			*operation;
	struct s_data	*left;
	struct s_data	*right;
}					t_data;

typedef struct		s_memory
{
	char			*var;
	char			*home;
	char			*line;
	char			*mode_quote;
	int				*type_quote;
	int				ll;
	int				pos;
}					t_memory;

typedef struct		s_built
{
	char			*str;
	int				(*f)(t_data *, t_llist *, t_memory *);
}					t_built;

int					prompt(t_llist *env);

void				ft_print_error(char *error, const char *str);
int					manage_error(int cod, t_data *data, t_llist *env,
								t_memory *me);
int					ft_echo(t_data *data, t_llist *env, t_memory *memory);
int					ft_variable(t_data *data, t_llist *env, t_memory *memory);
int					ft_cd(t_data *data, t_llist *env, t_memory *memory);
int					ft_env(t_data *data, t_llist *env, t_memory *memory);
int					ft_unsetenv(t_data *data, t_llist *env, t_memory *memory);
int					ft_setenv(t_data *data, t_llist *env, t_memory *memory);
int					ft_toexport(t_data *data, t_llist *env, t_memory *memory);
int					my_setenv(t_llist **env, char **environ, const char *value);
char				**my_env(t_llist *env);
int					export_var(t_llist **env, char *var);
int					export_var0(t_llist **env, char *var, char **option,
								int index);
int					unenv(char *unset, t_llist *env);

int					exec_cmd(t_memory *memo, t_llist *env);

int					parser_data(t_llist *env, char **line, t_data **data,
						t_memory **memory);
char				*search_env(t_llist *env, const char *value);
void				free_d(char **dtab, int lenght);
char				**init_option(char *opt, char **save);
int					option_ctrl(t_data *data, t_memory *memory, char **line);
void				init_data(t_llist *env, char *line, t_data **data);

t_data				*build_data();

int					ctrl_var(char *line);
int					my_ctrl(int test);
char				*is_bulltin(char *cmd);
char				*bin_checkout(char *line, t_llist *env);
int					operator_filters(char *line);

int					define_variable(t_memory *memory, char *line);
int					*generate(int c, int c1, int size);
#endif
