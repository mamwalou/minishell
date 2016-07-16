/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 21:46:40 by salomon           #+#    #+#             */
/*   Updated: 2016/07/16 18:00:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

void		init_term(struct termios *term, char *name_term)
{
	if (tgetent(NULL, name_term) == ERR)
		return ;
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag &= ~(ICANON|ECHO|ISIG);
	term->c_cc[VMIN] = 0;
	term->c_cc[VTIME] = 0;
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

int			ctrl_input(struct termios *term, char *name_term, char **line)
{
	char	buffer[3];
	char	*tmp_line;

	while (buffer[0] != RETURN)
	{
		ft_bzero(buffer, 3);
		init_term(term, name_term);
		read(0, buffer, 3);
		if (buffer[0] == 4)
		{
			termcaps_exit("close",term);
			return (-1);
		}
		cpy_on_line(buffer[0]);
		ft_putchar(buffer[0]);
	}
	return (1);
}

int			termcaps(t_llist *env, char **line)
{
	struct termios		term;
	char				*name_term;

	if ((name_term = search_env(env, "TERM")) == NULL)
		return (-1);
	if (ctrl_input(&term, name_term, line) == -1)
		return (-1);
	return (0);
}
