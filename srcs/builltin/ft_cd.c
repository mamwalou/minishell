#include "../../includes/minishell.h"

static int			ft_cdoneopt(t_data *data, t_llist *env, char *cpy)
{
	char			*buf;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	chdir(ft_strtrijoin(search_env(env, "PWD="), "/", data->option[0]));
	unenv("PWD=", env);
	unenv("OLDPWD=", env);
	free(buf);
	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	export_var(&env, ft_strjoin("PWD=", buf));
	export_var(&env, ft_strjoin("OLDPWD=", cpy));
	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	return (0);
}

int					ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char			*cpy;
	int				i;

	i = 0;
	cpy = ft_strdup(search_env(env, "PWD="));
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
	if ((i == 1) && (is_dir(data->option[0]) == REP))
		return (ft_cdoneopt(data, env, cpy));
	return (1);
}
