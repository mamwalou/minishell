#include "../../includes/minishell.h"

int			ft_cd(t_data *data, t_llist *env)
{
	char 	*cpy;
	char	*buf;
    if (data->option == NULL)
	{
		chdir(search_env(env, "HOME="));
		ft_unsetenv(data, env);
	}
	return (1);
}
