#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal    g_tableau[CNT_TERM] =
{
    {DELETE, ft_del},
    {SPACE, ft_space},
};

int			ft_space(char *line, struct termios *term, t_window *win)
{
	win->pos[0]++;
	win->lineshell++;
	ft_putchar(' ');
    return (SPACE);
}

int			ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int			ft_del(char *line, struct termios *term, t_window *win)
{
	char	*ret;

	if (win->lineshell > 0)
	{
		win->lineshell--;
		ret = depushline(line, win);
		tputs(tgoto(tgetstr("le", 0), win->pos[0], win->pos[1]), 1, ft_puts);
		ft_putchar(' ');
		tputs(tgoto(tgetstr("le", 0), win->pos[0], win->pos[1]), 1, ft_puts);
	}
	return (DELETE);
}

int			termc_ctrl(char c, char *line, struct termios *term, t_window *win)
{
    int		i;

    i = 0;
    while (i < CNT_TERM)
    {
        if (g_tableau[i].input == c)
            return (g_tableau[i].f(line, term, win));
        i++;
    }
    return (0);
}
