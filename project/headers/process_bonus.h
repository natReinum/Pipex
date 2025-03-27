/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:47:37 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/19 19:52:30 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_BONUS_H
# define PROCESS_BONUS_H
# include "../struct/command_struct.h"
# include "../struct/family_struct.h"
# include <unistd.h>
# include "utils.h"
# include "error_handler.h"
# include "pipex_bonus.h"

void	execute_first_child(t_family *family, t_command *command);
void	execute_middle_child(t_family *family, t_command *command);
void	execute_last_child(t_family *family, t_command *command);

#endif // PROCESS_BONUS_H
