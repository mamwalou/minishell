#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal    g_tableau[CNT_TERM] =
{
    {DELETE, ft_del},
    {SPACE, ft_space},
	{TAB, ft_search},
};

int			ft_space(t_window *win, t_llist *e, char *line)
{
	ft_putchar(' ');
    return (SPACE);
}

int			ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int			ft_del(t_window *win, t_llist *e, char *line)
{
	if (win->lineshell > 0)
	{
		win->lineshell--;
		tputs(tgoto(tgetstr("le", 0), win->pos[0], win->pos[1]), 1, ft_puts);
		ft_putchar(' ');
		tputs(tgoto(tgetstr("le", 0), win->pos[0], win->pos[1]), 1, ft_puts);
	}
	return (DELETE);
}

int			termc_ctrl(char *line, t_window *win, t_llist *e, int *code_term)
{
    int		i;
	int		ret;

    i = 0;
    while (i < CNT_TERM)
    {
        if (g_tableau[i].input == win->buffer[0])
		{
			if ((ret = g_tableau[i].f(win, e, line)) == TAB)
				*code_term = ret;
			return (ret);
		}
        i++;
    }
    return (0);
}
