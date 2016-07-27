/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:16:18 by salomon           #+#    #+#             */
/*   Updated: 2016/07/27 19:33:04 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H


# include <unistd.h>
# include <term.h>
# include <curses.h>
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

#define CNT_TERM 1

typedef struct          s_terminal
{
    int                input;
    char               *(*f)(char *);
}                       t_terminal;

int                     termcaps(t_llist *env , char **line);
char	               *push_line(char c, char *line);
char                   *termcap_check(char c, char *line);
char		           *depushline(char *line);

char                    *ft_space(char *line);
char                    *ft_del(char *line);
#endif
