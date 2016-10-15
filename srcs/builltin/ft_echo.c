#include "../../includes/minishell.h"

int 		ctrl_echo(char control, char *option)
{
	return (SUCCESS);
}

int 		parser_echo(t_data *data)
{
	int 	i;
	int		y;

	i = 0;
	while (i < data->index)
	{
		y = 0;
		while (data->option[i][++y])
			ctrl_echo(data->option[i][y], data->option[i]);
		i++;
	}
	return (SUCCESS);
}

int			ft_echo(t_data *data, t_llist *env, t_memory *memory)
{
	if (data->index == 0)
	{
		ft_putchar('\n');
		return (SUCCESS);
	}
	return (parser_echo(data));
}
