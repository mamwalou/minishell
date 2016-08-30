#include "../../includes/minishell.h"

static int			find_withparsing(char *VAR, char concat, char *line)
{
	char			**cpy;
	int				tableau[] = {(int)concat, 0};

	if (VAR)
	{
		if (ft_strsplit(&cpy, VAR, tableau) > 1)
			return (-1);
		return (0);
	}
	return (-1);
}

int			define_variable(t_memory *memory, char *line)
{
	if ((find_withparsing(memory->VAR, ';', line)) == 0)
	{
		memory->VAR = ft_strtrijoin(line, ";", memory->VAR);
		return (7);
	}
	memory->VAR = ft_strdup(line);
	return (6);

}

void		init_memory(t_memory *memory)
{
	memory->VAR = NULL;

}
