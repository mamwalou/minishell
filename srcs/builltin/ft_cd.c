#include "../../includes/minishell.h"

int			ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char 	*cpy;
	char	*buf;
	int		i;

	i = 1;
	cpy = search_env(env, "PWD=");
	ft_putendl(cpy);
    if (data->option == NULL)
	{
		chdir(search_env(env, "HOME="));
		unenv("PWD=", env);
		unenv("OLDPWD=", env);
		export_var(&env, ft_strjoin("PWD=", search_env(env, "HOME=")));
		export_var(&env, ft_strjoin("OLDPWD=", cpy));
		return (1);
	}
	while (data->option[i])
		i++;
	if (i > 2)
		return (48);
	if (is_dir(data->option[i]))
	{
		chdir(ft_strtrijoin(search_env(env, "PWD=") , "/", data->option[0]));
		unenv("PWD=", env);
		unenv("OLDPWD=", env);
		buf = ft_memalloc(UCHAR_MAX);
		getcwd(buf, UCHAR_MAX);
		export_var(&env, ft_strjoin("PWD=", buf));
		export_var(&env, ft_strjoin("OLDPWD=", cpy));
	}
	return (1);
}
