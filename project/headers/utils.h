/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:49:22 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 18:56:17 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <sys/wait.h>
# include "error_handler.h"
# include "process.h"
# include "pipex.h"
# include "../struct/family_struct.h"
# include "../struct/command_struct.h"

t_command	*get_list_last(t_command *command);
int			execute_cmd(t_command *cmd, char **env);
char		**get_cmd_args(char **cmd_args);
void		conceive_better_child(t_family *family, t_command *cmd);
void		conceive_less_important_child(t_family *family, t_command *cmd);
int			angry_parent_wait_for_children(t_family *family);
int			assign_infile(const char *path);
int			assign_outfile(const char *path);
void		fill_fd_array(t_family *family);

#endif // UTILS_H
