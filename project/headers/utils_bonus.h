/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:10:45 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 14:10:45 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H
# include <unistd.h>
# include "error_handler.h"
# include "process_bonus.h"
# include "../libft/libft.h"
# include "../struct/family_struct.h"
# include "../struct/command_struct.h"

char	*get_input(int fd);
t_error	call_command(t_family *family);
void	add_command_to_list(t_command **cmd_list, t_command *command);
void	conceive_forgotten_children(t_family *family, t_command *start, \
									t_command *end);
int		assign_infile_bonus(const char *path, t_family *family);
void	fill_fd_array(t_family *family);

#endif // UTILS_BONUS_H
