#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int					count_line(char *line, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		ft_putnbr(i);
		ft_putchar(line[i]);
		if (line[i] == ' ')
		{
			i++;
			ft_putnbr(i);
			if (i == lenght - 1)
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int					ft_search(t_window *win, t_llist *e, char *line)
{
	struct dirent 	*fl;
	DIR				*ir;
	char			**dline;

	if (win->lineshell == 0)
	{
		ft_putchar('\t');
		return (0);
	}
	if (count_line(line, win->lineshell) > 0)
	{
		if (line[win->lineshell - 1] == ' ')
		{
			if ((ir = opendir(search_env(e, "PWD="))) == NULL)
				exit (1);
			while ((fl = readdir(ir)) != NULL)
			{
				ft_putstr(fl->d_name);
				ft_putchar('\t');
			}
		}
	}
	return (0);
}
