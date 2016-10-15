#include "../../includes/minishell.h"

int			*generate(int c, int c1, int size)
{
	int		*tableau;

	tableau = (int*)ft_memalloc(sizeof(int) * size);
	if (size == 2)
	{
		tableau[0] = c;
		tableau[1] = 0;
		tableau[2] = 0;
	}
	if (size == 3)
	{
		tableau[0] = c;
		tableau[1] = c1;
		tableau[2] = 0;
		tableau[2] = 0;
	}
	return (tableau);
}

void		free_d(char **dtab, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		free(dtab[i]);
		i++;
	}
	if (lenght != 0)
		free(dtab);
}


int			parser_data(t_llist *env, char **line, t_data **data, t_memory **me)
{
	(*me)->pos = 0;
	while (line[(*me)->pos])
	{
		if (ctrl_var(line[(*me)->pos]))
		{
			if (*data == NULL)
				*data = init_data(env, line[(*me)->pos]);
			else
			{
				(*data)->index += 1;
				option_ctrl(*data, *me, &line[(*me)->pos]);
			}
			if (!(*data)->cmd)
				return (-1);
		}
		if (!ctrl_var(line[(*me)->pos]))
			return (define_variable(*me, line[(*me)->pos]));
		(*me)->pos++;

	}
	return (0);
}
