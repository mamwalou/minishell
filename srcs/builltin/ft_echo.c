/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:48:55 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 15:08:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	duo_quote(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 92)
			;
		if (!line[i + 1])
		{
			ft_putchar('\n');
			return(SUCCESS);
		}
		ft_putchar(line[i]);
		i++;
	}
	return (ER_EXIT);
}

int			parser_echo(t_data *data, t_memory *memory)
{
	char	*ptr;
	int 	i;

	i = 1;
	ptr = memory->line + 5;
	if (*ptr == 34)
		return (duo_quote(ptr + 1));
	else if (*ptr == 39)
	{
		while (ptr[i])
		{
			if (!ptr[i + 1])
			{
				ft_putchar('\n');
				return (SUCCESS);
			}
			ft_putchar(ptr[i]);
			i++;
		}
	}
	ft_putendl(ptr);
	return (SUCCESS);
}

int			ft_echo(t_data *data, t_llist *env, t_memory *memory)
{
	int		i;

	i = 1;
	if (data->index == 1)
	{
		ft_putchar('\n');
		return (SUCCESS);
	}
	parser_echo(data, memory);
	return (SUCCESS);
}
