#include "../../includes/minishell.h"

int			define_variable(t_memory *memory, char *line)
{
	char			**cpy;

	if (memory->var)
	{
		memory->var = ft_strtrijoin(line, ";", memory->var);
		return (7);
	}
	else
		memory->var = ft_strdup(line);
	return (6);
}

int			ft_variable(t_data *data, t_llist *env, t_memory *memory)
{
	ft_putendl(memory->var);
	return (0);
}
