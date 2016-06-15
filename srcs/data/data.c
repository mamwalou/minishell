#include "../../includes/minishell.h"

char			**push_option(char *opt, char **save)
{
	char		**nw_opt;
	int			pos;

	pos = 1;
	if (save == NULL)
	{
		nw_opt = (char**)malloc(sizeof(char*));
		nw_opt[0] = ft_strdup(opt);
		nw_opt[pos] = 0;
	}
	return (nw_opt);
}

t_data			*init_data(t_llist *env, char *line)
{
	t_data		*data;
	int			ctrl;

	data = NULL;
	data->left == NULL;
	data->right == NULL;
	data->cmd == NULL;
	data->operation == NULL;
	data->option == NULL;
	data = (t_data*)ft_memalloc(sizeof(t_data));
	if ((data->cmd = bin_checkout(line, env)) != NULL)
	{
		data->option = push_option(data->cmd, data->option);
		return (data);
	}
	if ((data->cmd = is_bulltin(line)) != NULL)
		return (data);
	return (data);
}