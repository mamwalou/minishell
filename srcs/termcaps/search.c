#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int					count_line(char *line, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		if (line[i] == ' ')
		{
			if (i == lenght)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void 				list_files(t_window *win, t_llist *dline, int tabulation)
{
	int				lenght_line;

	lenght_line = 0;

	tputs(tgetstr("sc", 0), 1, ft_puts);
	ft_putchar('\n');
	while (dline)
	{
		if (tabulation )
		ft_putstr(dline->content);
		ft_putchar('\t');
		dline = dline->next;
	}
	tputs(tgetstr("rc", 0), 1, ft_puts);
	tputs(tgoto(tgetstr("cm", 0),win->pos[0] + 1, win->pos[1] - 3), 1, ft_puts);
}

void 				path_found(t_window *win, t_llist *e, char *line)
{
	DIR				*ir;
	t_llist			*dline;
	char			*save;
	int				tabulation;

	dline = NULL;
	if ((ir = opendir(search_env(e, "PWD="))) == NULL)
		exit (1);
	tabulation = created_path(ir, &dline);
	list_files(win, dline, tabulation);
}

void 				path_found1(t_window *win, t_llist *e, char *line)
{
	DIR				*ir;
	t_llist			*dline;
	int				lenght;
	int				tabulation;

	dline = NULL;
	if ((ir = opendir(search_env(e, "PWD="))) == NULL)
		exit (1);
	tabulation = created_path(ir, &dline);
	list_files(win, dline, tabulation);
}

int					ft_search(t_window *win, t_llist *e, char *line)
{
	if (win->lineshell == 0)
	{
		ft_putchar('\t');
		return (0);
	}
	if (count_line(line, win->lineshell) > 0)
	{
		if (line[win->lineshell - 1] == ' ')
			path_found(win, e, line);
		else if (ft_isalnum(line[win->lineshell - 1]) == 1)
			path_found1(win, e, line);
	}
	return (TAB);
}
