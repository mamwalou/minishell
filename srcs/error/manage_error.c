#include "../../includes/minishell.h"

void			ft_print_error(char *error, const char *str)
{
	ft_putstr(error);
	ft_putendl(str);
}

static void		error_memory(int cod, t_data *data, t_llist *env, t_memory *me)
{
	if (cod == ER_MMR)
		ft_putendl("no variable in memory");
	if (cod == ER_PREMMR)
	{
		ft_env(data, env, me);
		ft_putendl("-------------------------------------");
		ft_putendl("	in memory");
		ft_putendl("-------------------------------------");
		ft_toexport(data, env, me);
		ft_putendl("some var already set: need precision");
	}
	if (cod == ER_USEVR)
		ft_putendl("Use unset/set 'variable'");
}

int				manage_error(int cod, t_data *data, t_llist *env, t_memory *me)
{
	error_memory(cod, data, env, me);
	if (cod == ER_CMDNF)
		ft_putendl(" :CMD not found");
	if (cod == ER_PATHNF)
	{
		ft_putstr(data->option[0]);
		ft_putendl(" :PATH variable not found");
	}
	if (cod == ER_CDPWDNF)
	{
		ft_putstr("cd: string not in pwd:");
		ft_putendl(data->option[0]);
	}
	if (cod == ER_NTFORD)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(data->option[0]);
	}
	if (cod == ER_EXIT)
	{
		ft_putendl("Good bye, have fun");
		return (-1);
	}
	return (0);
}
