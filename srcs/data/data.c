#include "../../includes/minishell.h"

static char			**push_option(char *opt, char **save)
{
	int				pos;
	char			**nw_opt;
	int				count;

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

char				**init_option(char *opt, char **save)
{
	char			**nw_opt;
	int				pos;

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

char				*clear_car(char *line, int *tab)
{
	char			*cpy;
	int				count;
	int				i;
	int				j;

	count = 0;
	while (line[i])
	{

		i++;
	}
}

void				init_data(char *line, t_memory *memory, t_data **data)
{
	char			*blank;

	if (*line[0] == 39 && *line[0] == 34)
	{
		if (((*data)->cmd = is_bulltin(line)) != NULL)
		{
			(*data)->index += 1;
			(*data)->option = init_option((*data)->cmd, (*data)->option);
			return ;
		}
		if (((*data)->cmd = bin_checkout(line, env)) != NULL)
		{
			(*data)->index += 1;
			(*data)->option = init_option((*data)->cmd, (*data)->option);
			(*data)->index = 0;
			return ;
		}
		return ;
	}
	else
	{
		blank = clear_car(line, generate(39, 34, 3));
		init_data(blank, memory, data);
	}
}

t_data				*build_data()
{
	t_data  *data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	data->index = 0;
	data->cmd = 0;
	data->option = NULL;
	data->operation = NULL;
	data->left = NULL;
	data->right = NULL;
	return (data);
}
