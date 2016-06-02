/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtunsh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:43 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenghtunsh(unsigned short ll)
{
	size_t	ret;

	ret = 1;
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
