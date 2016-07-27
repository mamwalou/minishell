#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal    g_tableau[CNT_TERM] =
{
    //{DELETE, ft_del},
    {SPACE, ft_space},
};

char                    *ft_space(char *line)
{
    return (push_line(' ', line));
}

/*char                    *ft_del(char *line)
{
	bring_back_shell
    return (depushline(line));
}*/

char                    *termcap_check(char c, char *line)
{
    int                 i;

    i = 0;
    while (i < CNT_TERM)
    {
        if (g_tableau[i].input == c)
            return (g_tableau[i].f(line));
        i++;
    }
    return (line);
}
