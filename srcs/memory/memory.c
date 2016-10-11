#include "../../includes/minishell.h"

char		*can_var(char *var, char *line)
{
	char	**array;
	char	*cpy;
	int		i;
	int		len;

	i = 0;
	len = ft_strsplit(&array, var, generate(';', 0, 2));
	cpy = ft_strdup(var);
	while (array[i])
	{
		if (ft_strncmp(array[i], line, ft_strlen(line)))
		{
			cpy = ft_strtrijoin()
		}
		i++;
	}
	return (cpy);

}

int			define_variable(t_memory *memory, char *line)
{
	char			**cpy;

	if (memory->var)
	{
		memory->var = can_var(memory->var, line);
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
