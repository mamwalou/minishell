#include "../../includes/minishell.h"

void 		free_d(char **dtab, int lenght)
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

int		parser_data(t_llist *env, char **line, t_data **data)
{
	while (*line)
	{
		if (*data == NULL)
		{
			*data = init_data(env, *line);
			if (!(*data)->cmd)
				return (-1);
		}
		else
		{
			if ((data_filters(*line)) > 0)
				;
			((*data)->option) = push_option(*line, (*data)->option);
		}
		line++;
	}
	return(1);
}
