/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:53:21 by sbeline           #+#    #+#             */
/*   Updated: 2015/02/12 17:27:08 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenght_array(char **str)
{
	int i;
	int	y;
	int n;

	i = 1;
	n = 0;
	while (str[i])
	{
		y = 0;
		while(str[i][y++])
			n++;
		i++;
	}
	return (n);
}
