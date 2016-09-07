#include "../../includes/minishell.h"

int			ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char 	*cpy;
	char	*buf;
	int		i;

	i = 1;
	exit(1);
    if (data->option[i] == NULL)
	{
		chdir(search_env(env, "HOME="));
		ft_unsetenv(data, env, memory);
		export_var(&env, ft_strjoin("PWD=", search_env(env, "HOME=")));
	}
	else
	{
		while (data->option[i])
			i++;
		if (i > 2)
			return (48);
		if (is_dir(data->option[i]))
			;
	}
	return (1);
}
