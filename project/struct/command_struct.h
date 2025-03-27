/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:49:01 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/27 13:34:45 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_STRUCT_H
# define COMMAND_STRUCT_H

typedef struct s_command
{
	char				*cmd_path;
	char				**cmd_arg;
	struct s_command	*next;
}				t_command;

#endif // COMMAND_STRUCT_H
