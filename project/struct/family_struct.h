/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:37:40 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 15:39:16 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAMILY_STRUCT_H
# define FAMILY_STRUCT_H
# include <stdlib.h>
# include "command_struct.h"

typedef struct s_family
{
	pid_t		pid;
	pid_t		last_child_pid;
	char		**env;
	int			here_doc;
	char		*infile;
	char		*outfile;
	int			**fd;
	int			i_fd;
	int			i_fd_max;
	t_command	*commands;
}				t_family;

#endif // FAMILY_STRUCT_H
