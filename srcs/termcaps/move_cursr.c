/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 23:57:26 by sbeline           #+#    #+#             */
/*   Updated: 2016/09/07 02:06:20 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int 			init_varfcurs()
{

	if (!(g_clear = tgetstr("cl", NULL))
		|| !(g_up = tgetstr("up", NULL))
		|| !(g_down = tgetstr("do", NULL))
		|| !(g_right = tgetstr("nd", NULL))
		|| !(g_left = tgetstr("le", NULL)))
			return (-1);
	return (1);
}

void			move_cursr(t_window *win, int mode, int iteration)
{
	if (mode == CUP)
	{
		while (iteration-- != 0)
			tputs(g_up, 1, ft_puts);
	}
	if (mode == CDOWN)
	{
		while (iteration-- != 0)
			tputs(g_down, 1, ft_puts);
	}
	if (mode == CLEFT)
	{
		while (iteration-- != 0)
			tputs(g_left, 1, ft_puts);
	}
	if (mode == CRIGHT)
	{
		while (iteration-- != 0)
			tputs(g_right, 1, ft_puts);
	}
}
