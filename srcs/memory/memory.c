#include "../../includes/minishell.h"

static int			find_withparsing(char *VAR, char concat, char *line)
{
	char **cpy;
	char *tableau[] = {concat, 0};

	if (ft_strsplit(&cpy, VAR, tableau) > 1)
		return (-1);
	return (0);
}

int			define_variable(t_memory *memory, char *line)
{
	int test;

	if (find_withparsing(memory->VAR, ';' line) == 0)
	{
		ft_strtrijoin(line, ";", memory->VAR);
		return (7);
	}
	memory->VAR = ft_strdup(line);
	return (6);

}

void		init_memory(t_memory *memory)
{
	memory->VAR = NULL;

}
