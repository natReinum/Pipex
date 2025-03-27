/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:18:15 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 19:32:13 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include "parser_bonus.h"
# include "error_handler.h"
# include "../struct/family_struct.h"
# include "here_doc_bonus.h"

void	perform_illegal_act_on_family_2(t_family **family, int del_here, \
										int close_fds);

#endif // PIPEX_BONUS_H
