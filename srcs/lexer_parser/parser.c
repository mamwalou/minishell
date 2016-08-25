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

int		parser_data(t_llist *env, char **line, t_data **data, t_memory **memory)
{
	while (*line)
	{
		if (*data != NULL)
			((*data)->option) = init_option(*line, (*data)->option);
		if (*data == NULL && ctrl_var(*line))
		{
			*data = init_data(env, *line);
			if (!(*data)->cmd)
				return (-1);
		}
		if (!ctrl_var(*line))
			return (define_variable(*memory, *line));
		line++;
	}
	return(0);
}
