#include "../../includes/minishell.h"

static int		unenv(char *unset, t_llist *env)
{
	t_llist 	*ptr;
	t_llist		*save;
	t_llist		*to_next;

	ptr = env;
	if (unset[ft_strlen(unset)] != '=')
		ft_strjoin(unset, "=");
	while (ptr)
	{
		if (!ft_strncmp((const char*)ptr->content, unset, ft_strlen(unset)))
		{
			to_next = ptr->next;
			free(ptr->content);
			free(ptr);
			save->next = to_next;
			return (0);
		}
		save = ptr;
		ptr = ptr->next;
	}
	return (2);
}

int				ft_unsetenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist		*ptr;
	char		*buf;

	ptr = env;
	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	return (unenv(data->option[0], env));
}
