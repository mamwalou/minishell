/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_compl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 18:08:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/09/07 02:45:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

char 		*tabulation(char *line, t_window *win)
{
	tputs(tgetstr("sc", NULL), 1, ft_puts);
	move_cursr(win, CDOWN, 1);
	tputs(tgetstr("dl", NULL), 1, ft_puts);
	tputs(tgetstr("rc", NULL), 1, ft_puts);
	move_cursr(win, CUP, 1);
	move_cursr(win, CRIGHT, win->pos[0] + 1);
	return (line);
}
