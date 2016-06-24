/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 21:46:40 by salomon           #+#    #+#             */
/*   Updated: 2016/06/20 16:47:18 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

void	init_term(struct termios *term, char *name_term)
{
	if (tgetent(NULL, name_term) == ERR)
		return ;
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag &= ~(ICANON|ECHO);
	term->c_cc[VMIN] = 0;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return ;

}

void 	bring_back_shell(struct termios *term)
{
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag = (ICANON|ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return ;
}

void 	termcaps_exit(const char *exit_msg, struct termios *term)
{
	if (exit_msg)
		ft_putendl(exit_msg);
	bring_back_shell(term);
	ft_putchar('\n');
	exit (-1);
}

int		ctrl_input(struct termios *term)
{
	char buffer[3];

	read(0, buffer, 3);
	if (buffer[0] == 4)
	{
		bring_back_shell(term);
		return (-1);
	}
	return (1);
}

int		termcaps(t_llist *env, char **cmd)
{
	struct termios		term;
	char				*name_term;

	if ((name_term = search_env(env, "TERM")) == NULL)
		return ;
	init_term(&term, name_term);
	if (ctrl_input(&term) == -1)
		return (-1);
	bring_back_shell(&term);
	return (0);
}
