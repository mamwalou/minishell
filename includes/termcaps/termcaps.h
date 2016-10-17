/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:16:18 by salomon           #+#    #+#             */
/*   Updated: 2016/10/17 15:15:01 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <dirent.h>
# include "../../libft/Includes/libft.h"
# include "../minishell.h"
# define ESCAPE      27
# define SPACE       32
# define UP          4283163
# define LEFT        4479771
# define RIGHT       4414235
# define DOWN        4348699
# define RETURN      10
# define DELETE      127
# define BACKSPACE   2117294875
# define HOME        4741915
# define END         4610843
# define PAGEDOWN    2117491483
# define PAGEUP      2117425947
# define CTRL_C      3
# define CTRL_D      4
# define CTRL_L      12
# define CTRL_Z      26
# define CTRL_R      18
# define SHIFT_LEFT  17458
# define SHIFT_RIGHT 17202
# define SHIFT_UP    16690
# define SHIFT_DOWN  16946
# define SHIFT       993090331
# define TAB		 9
# define CTRL_SPACE  0
# define CTRL_X      24
# define CNT_TERM	4
# define CDOWN		98
# define CUP		97
# define CLEFT		96
# define CRIGHT		95
# define JTAB		100

char g_buf[512];
char *g_left;
char *g_clear;
char *g_up;
char *g_down;
char *g_right;
char *g_save;
char *g_reset;
char *g_resline;

typedef struct	s_window
{
	int			begin;
	int			lenght;
	int			column;
	int			lineshell;
	char		*save;
	char		buffer[4];
	int			pos[2];
	int			set;
}				t_window;

typedef struct	s_terminal
{
	int			input;
	int			(*f)(t_window *, t_llist *, char *);
}				t_terminal;

int				termcaps(t_llist *env, char **line, int lenght_prompt,
						t_window *win);

int				init_varfcurs();

int				ft_puts(int c);
void			bring_back_shell(struct termios *term);

t_llist			*created_path(int *tabulation, t_llist *e, char *value);
char			*parsing_term(int code, char *line, t_window *win);
char			*depushline(char *line, t_window *win);
char			*push_line(char c, char *line, t_window *win);
char			*tabulation(char *line, t_window *win);
int				termc_ctrl(char *line, t_window *w, t_llist *e, int *c);

int				ft_space(t_window *win, t_llist *e, char *line);
int				ft_del(t_window *win, t_llist *e, char *line);
int				ft_search(t_window *win, t_llist *e, char *line);
int				ft_clear(t_window *win, t_llist *e, char *line);

void			move_cursr(t_window *win, int mode, int iteration);

#endif
