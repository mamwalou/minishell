/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 23:57:40 by sbeline           #+#    #+#             */
/*   Updated: 2016/09/08 15:04:37 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal	g_tableau[CNT_TERM] =
{
	{DELETE, ft_del},
	{SPACE, ft_space},
	{CTRL_L, ft_clear},
	{TAB, ft_search},
};

int						ft_space(t_window *win, t_llist *e, char *line)
{
	ft_putchar(' ');
	return (SPACE);
}

int						ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int						ft_clear(t_window *win, t_llist *e, char *line)
{
	tputs(g_clear, 1, ft_puts);
	prompt(e);
	if (line)
		ft_putstr(line);
	return (CTRL_L);
}

int						ft_del(t_window *win, t_llist *e, char *line)
{
	if (win->lineshell > 0)
	{
		win->lineshell--;
		move_cursr(win, CLEFT, 1);
		ft_putchar(' ');
		move_cursr(win, CLEFT, 1);
	}
	return (DELETE);
}

int						termc_ctrl(char *line, t_window *w, t_llist *e, int *c)
{
	int		i;
	int		ret;

	i = 0;
	while (i < CNT_TERM)
	{
		if (g_tableau[i].input == w->buffer[0])
		{
			if ((ret = g_tableau[i].f(w, e, line)) == TAB)
				*c = ret;
			return (ret);
		}
		i++;
	}
	return (0);
}
