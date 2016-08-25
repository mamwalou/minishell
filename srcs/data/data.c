#include "../../includes/minishell.h"

static char			**push_option(char *opt, char **save)
{
	int			pos;
	char		**nw_opt;
	int			count;

	pos = 0;
	count = 0;
	while (save[pos])
		pos++;
	pos += 1;
	nw_opt = (char**)malloc(sizeof(char*) * pos + 1);
	while (save[count])
	{
		nw_opt[count] = ft_strdup(save[count]);
		count++;
	}
	nw_opt[count] = ft_strdup(opt);
	nw_opt[count + 1] = 0;
	return (nw_opt);
}

char			**init_option(char *opt, char **save)
{
	char		**nw_opt;
	int			pos;

	if (save == NULL)
	{
		pos = 1;
		nw_opt = (char**)malloc(sizeof(char*));
		nw_opt[0] = ft_strdup(opt);
		nw_opt[pos] = 0;
		return (nw_opt);
	}
	else
		return (push_option(opt, save));
	return (nw_opt);
}

t_data			*init_data(t_llist *env, char *line)
{
	t_data		*data;

	data = NULL;
	data = (t_data*)ft_memalloc(sizeof(t_data));
	if ((data->cmd = is_bulltin(line)) != NULL)
		return (data);
	if ((data->cmd = bin_checkout(line, env)) != NULL)
	{
		data->option = init_option(data->cmd, data->option);
		return (data);
	}
	return (data);
}
