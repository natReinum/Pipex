/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:30:15 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/27 13:35:56 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H
# include <unistd.h>
# include <errno.h>
# include <stdio.h>

typedef enum e_error
{
	success,
	malloc_err,
	param_count_err,
	infile_fd_err,
	outfile_fd_err,
	pipe_err,
	fork_err,
	path_err,
	param_count_here_doc_err
}			t_error;

t_error	handle_error(t_error *error);

#endif // ERROR_HANDLER_H
