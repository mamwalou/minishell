#include "../../includes/minishell.h"

int			ft_cd(t_data *data, t_llist *env)
{
	char *cpy;

    if (data->option == NULL)
	{
		chdir(search_env(env, "HOME="));
		cpy = search_env(env, "HOME=");
		data->option[0] = ft_strdup("PWD=");
		ft_unsetenv(data, env);
	}
	return (1);
}
