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

void 				path_found(t_window *win, t_llist *e, char *line)
{
	struct dirent 	*fl;
	DIR				*ir;

	if ((ir = opendir(search_env(e, "PWD="))) == NULL)
		exit (1);
	ft_putchar('\n');
	while ((fl = readdir(ir)) != NULL)
	{
		ft_putstr(fl->d_name);
		ft_putchar('\t');
	}
	ft_putchar('\n');
	prompt(e);
	ft_putstr(line);
}

void 				path_found1(t_window *win, t_llist *e, char *line)
{
	struct dirent 	*fl;
	DIR				*ir;
	char			**dline;
	int 			tableau[2] = {32, 0};
	int				lenght;

	lenght = ft_strsplit(&dline, line, tableau);
	if ((ir = opendir(search_env(e, "PWD="))) == NULL)
		exit (1);
	ft_putchar('\n');
	while ((fl = readdir(ir)) != NULL)
	{
		ft_putstr(fl->d_name);
		ft_putchar('\t');
	}
	ft_putchar('\n');
	prompt(e);
	ft_putstr(line);
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
	return (0);
}
