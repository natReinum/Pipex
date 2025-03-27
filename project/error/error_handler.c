/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:30:15 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/21 17:16:58 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error_handler.h"

static t_error	reset_error(t_error *error)
{
	t_error	rtn_val;

	rtn_val = *error;
	*error = success;
	return (rtn_val);
}

t_error	handle_error(t_error *error)
{
	if (*error == malloc_err)
		return (write(2, "a malloc error occurred!\n", 25), malloc_err);
	if (*error == param_count_err)
		return (write(2, "syntax: ./pipex file1 cmd1 cmd2 file2\n", 38), \
				param_count_err);
	if (*error == infile_fd_err)
		return (perror("Could not open or read the infile"), \
				reset_error(error));
	if (*error == outfile_fd_err)
		return (perror("Could not create or write in the outfile"), \
				outfile_fd_err);
	if (*error == pipe_err)
		return (perror("pipe error"), pipe_err);
	if (*error == fork_err)
		return (perror("fork error"), fork_err);
	if (*error == path_err)
		return (write(2, "command not found or not reachable\n", 35), \
				reset_error(error));
	return (0);
}
