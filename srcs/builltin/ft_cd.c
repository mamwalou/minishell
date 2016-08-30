#include "../../includes/minishell.h"

int			ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char 	*cpy;
	char	*buf;

    if (data->option == NULL)
	{
		chdir(search_env(env, "HOME="));
		ft_unsetenv(data, env, memory);
	}
	return (1);
}
