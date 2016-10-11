#include "../../includes/minishell.h"

void				ft_print_error(char *error, const char *str)
{
	ft_putstr(error);
	ft_putendl(str);
}

int					manage_error(int code_err, t_data *data, t_llist *env)
{
	if (code_err == ER_CMDNF)
		ft_putendl(" :CMD not found");
	if (code_err == ER_MMR)
		ft_putendl("no variable in memory");
	if (code_err == ER_PREMMR)
		ft_putendl("some var already set: need precision");
	if (code_err == ER_PATHNF)
	{
		ft_putstr(data->option[0]);
		ft_putendl(" :PATH variable not found");
	}
	if (code_err == ER_CDPWDNF)
	{
		ft_putstr("cd: string not in pwd:");
		ft_putendl(data->option[0]);
	}
	if (code_err == ER_USEVR)
		ft_putendl("Use unset/set 'variable'");
	if (code_err == ER_NTFORD)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(data->option[0]);
	}
	if (code_err == ER_EXIT)
	{
		ft_putendl("Good bye, have fun");
		return (-1);
	}
	return (0);
}
