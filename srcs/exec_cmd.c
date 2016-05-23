#include "../includes/minishell.h"


int			is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "setenv") == 0
		|| ft_strcmp(cmd, "unsetenv") == 0
		|| ft_strcmp(cmd, "cd") == 0)
		return (1);
	return (0);
}


void 		exec_cmd(char **environ, char *line)
{
	pid_t	process;
	t_data	*data;

	data = NULL;
	parser(environ, line, data);
}
