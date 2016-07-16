#include "../../includes/minishell.h"

char			*search_env(t_llist *env, const char *value)
{
	t_llist		*ptr;

	ptr = env;
	while (ptr)
	{
		if ((ft_findstr(ptr->content, (char*)value)) == 1)
			return (ptr->content + ft_strchr(ptr->content, '='));
		ptr = ptr->next;
	}
	return (NULL);
}

char			**my_env(t_llist *env)
{
	t_llist 	*ptr;
	char		**ret;
	int			count;

	count = 0;
	ptr = env;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ret = (char**)malloc(sizeof(char*) * ptr->maillon_nb + 1);
	ptr = env;
	while (ptr)
	{
		ret[count] = ft_strdup(ptr->content);
		count++;
		ptr = ptr->next;
	}
	ret[count] = "\0";
	return (ret);
}
