/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 21:46:40 by salomon           #+#    #+#             */
/*   Updated: 2016/08/17 19:19:24 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

void		init_term(struct termios *term, char *name_term, t_window *data)
{
	if (tgetent(NULL, name_term) == ERR)
		return ;
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag &= ~(ICANON|ECHO|ISIG);
	term->c_cc[VMIN] = 0;
	term->c_cc[VTIME] = 0;
	data->lenght = tgetnum("li");
	data->column = tgetnum("co");
	data->lineshell = 0;
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



int			termcaps(t_llist *env, char **line)
{
	struct termios		term;
	t_window			win;
	char				*name_term;
	char				buffer[3];

	if ((name_term = search_env(env, "TERM=")) == NULL)
		return (-1);
	init_term(&term, name_term, &win);
	while (buffer[0] != RETURN)
	{
		ft_bzero(buffer, 3);
		read(0, buffer, 3);
		if (buffer[0] == CTRL_D)
			termcaps_exit("close", &term);
		if ((ft_isalpha(buffer[0])) == 1 || (my_ctrl(buffer[0])) == 1)
			*line = push_line(buffer[0], *line, &win);
		else
			*line = termc_ctrl(buffer[0], *line, &term, &win);
		ft_putchar(buffer[0]);
		win.save = tgetstr("sc", NULL);
	}
	bring_back_shell(&term);
	return (0);
}
