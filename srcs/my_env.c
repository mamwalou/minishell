#include "../includes/minishell.h"

char		*search_env(char **environ, const char *value)
{
	while (*environ != NULL)
	{
		if ((ft_findstr(*environ, (char*)value)) == 1)
			return (*environ + ft_strchr(*environ, '='));
		environ++;
	}
	return (NULL);
}
