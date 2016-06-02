#include "../includes/minishell.h"
#include <stdio.h>

static int		find_occur(const char *s, char c)
{
	int			ret;

	ret = 0;
	while (*s)
	{
		if (*s == c)
		{
			ret++;
			while (*s == c)
				*s++;
		}
		s++;
	}
	return(ret);
}

int			filters(char *pline, t_data *data)
{
	char *tab[8];
	int		i;

	tab[0] = ">";
	tab[1] = "<";
	tab[2] = ">&";
	tab[3] = ">!";
	tab[4] = ">!&";
	tab[5] = "|";
	tab[6] = ">>";
	tab[7] = ">>&";
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp(tab[i], pline))
			return (1);
		i++;
	}
	return (0);
}

int 		access_check(char *pline, char **bin)
{
	if (access(ft_strtrijoin(*bin, "/", pline), X_OK) == 0)
		return (1);
	else
		return (0);
}

void 		free_d(char **dtab, int lenght)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		free(dtab[i]);
		i++;
	}
	free(dtab);
}

void 		parser(char **environ, char *line, t_data *data)
{
	char		**bin;
	char		**pline;
	char		*tmp;
	int			lenght;
	int			lenght_bin;



	lenght_bin = ft_strsplit(&bin ,search_env(environ, "PATH"), ':');
	lenght = ft_strsplit(&pline, line, ' ');
	if (*pline != NULL)
	{
		tmp = *pline;
		while (tmp)
		{
			if ((access_check(tmp, bin)) > 0)
				;
			if ((filters(tmp, data)) > 0)
			;
			tmp++;
		}
	}
	free_d(bin, lenght_bin);
	free_d(pline, lenght);
}