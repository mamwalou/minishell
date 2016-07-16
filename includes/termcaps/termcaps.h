/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon  <salomon @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:16:18 by salomon           #+#    #+#             */
/*   Updated: 2016/07/16 17:55:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H


# include <unistd.h>
# include <term.h>
# include <curses.h>
# include "../../libft/Includes/libft.h"
# include "../minishell.h"
# define RETURN 10
# define CTRL_D 4
# define CTRL_C 3

int		termcaps(t_llist *env , char **line);

#endif
