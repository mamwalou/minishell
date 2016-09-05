/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 21:46:40 by salomon           #+#    #+#             */
/*   Updated: 2016/09/05 21:13:48 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

void		init_term(struct termios *term, t_llist *e, t_window *data, int len)
{
	char				*name_term;

	if ((name_term = search_env(e, "TERM=")) == NULL)
		return ;
	if (tgetent(NULL, name_term) == ERR)
		return ;
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag &= ~(ICANON|ECHO|ISIG);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	data->lenght = tgetnum("li");
	data->column = tgetnum("co");
	data->lineshell = 0;
	data->pos[0] = len + 1;
	data->pos[1] = data->lenght;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return ;
}

void 		bring_back_shell(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag = (ICANON|ECHO|ISIG);
	if (tcsetattr(0, 0, term) == -1)
		return ;
}

void 		termcaps_exit(const char *exit_msg, struct termios *term)
{
	ft_putchar('\n');
	if (exit_msg)
		ft_putendl(exit_msg);
	bring_back_shell(term);
	exit (-1);
}

int			termcaps(t_llist *env, char **line, int lenght_prompt)
{
	struct termios		term;
	t_window			win;
	int					code;
	int					code_to_return;

	code_to_return = 0;
	init_term(&term, env, &win, lenght_prompt);
	while (win.buffer[0] != RETURN)
	{
		ft_bzero(win.buffer, 4);
		read(0, win.buffer, 4);
		if (win.buffer[0] == CTRL_D)
			termcaps_exit("close", &term);
		if ((ft_isalnum(win.buffer[0])) == 1 || (my_ctrl(win.buffer[0])) == 1)
		{
			*line = push_line(win.buffer[0], *line, &win);
			ft_putchar(win.buffer[0]);
		}
		else if ((code = termc_ctrl(*line, &win, env, &code_to_return)) > 0)
		{
			*line = parsing_term(code, *line, &win);
		}
	}
	if (code_to_return + RETURN == TAB + RETURN)
		tabulation(*line, &win);
	ft_putchar('\n');
	bring_back_shell(&term);
	return (0);
}
