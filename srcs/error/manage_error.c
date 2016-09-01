#include "../../includes/minishell.h"

void				ft_print_error(char *error, const char *str)
{
	ft_putstr(error);
	ft_putendl(str);
}

int					manage_error(int code_err, t_data *data, t_llist *env)
{
	if (code_err == -1)
		ft_putendl(" :CMD not found");
	if (code_err == 2)
	{
		ft_putstr(data->option[0]);
		ft_putendl(" :PATH variable not found");
	}
	if (code_err == 42)
	{
		ft_putendl("Good bye, have fun");
		return (-1);
	}
	return (0);
}
