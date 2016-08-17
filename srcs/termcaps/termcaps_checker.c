#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal    g_tableau[CNT_TERM] =
{
    {DELETE, ft_del},
    {SPACE, ft_space},
};

char		*ft_space(char *line, struct termios *term, t_window *win)
{
    return (push_line(' ', line, win));
}

int			ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

char        *ft_del(char *line, struct termios *term, t_window *win)
{
    char    *res;

    tputs(tgetstr("cl", 0), 1, ft_puts);
    bring_back_shell(term);
    return (depushline(line, win));
}

char		*termc_ctrl(char c, char *line, struct termios *term, t_window *win)
{
    int		i;

    i = 0;
    while (i < CNT_TERM)
    {
        if (g_tableau[i].input == c)
            return (g_tableau[i].f(line, term, win));
        i++;
    }
    return (line);
}
