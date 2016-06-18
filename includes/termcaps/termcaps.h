/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 22:16:18 by salomon           #+#    #+#             */
/*   Updated: 2016/06/17 20:52:55 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <termio.h>
# include <unistd.h>
# include <term.h>
# include <curses.h>
# include "../../libft/Includes/libft.h"
# include "../minishell.h"

int			termcaps(t_llist *env);

#endif
