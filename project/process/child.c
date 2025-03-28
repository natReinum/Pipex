/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:47:30 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 22:54:56 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <process.h>

void	execute_first_child(t_family *family, t_command *command)
{
	int	fd;

	ft_close(&family->fd[family->i_fd][0]);
	fd = family->fd_in;
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2 - STDIN");
		if (fd != -1)
			ft_close(&fd);
		perform_illegal_act_on_family(&family);
		exit(-42);
	}
	if (dup2(family->fd[family->i_fd][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 - STDOUT");
		if (fd != -1)
			ft_close(&fd);
		perform_illegal_act_on_family(&family);
		exit(-42);
	}
	execute_cmd(command, family->env);
	perform_illegal_act_on_family(&family);
	ft_close(&fd);
	exit(0);
}

void	execute_last_child(t_family *family, t_command *command)
{
	int	error_code;
	int	fd;

	error_code = 0;
	ft_close(&family->fd[family->i_fd - 1][1]);
	if (dup2(family->fd[family->i_fd - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 - STDIN");
		perform_illegal_act_on_family(&family);
		exit(-42);
	}
	fd = assign_outfile(family->outfile);
	if (fd == -1)
		(perform_illegal_act_on_family(&family), exit(errno));
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		(perror("dup2 - STDOUT"), perform_illegal_act_on_family(&family));
		(ft_close(&fd), exit(-42));
	}
	ft_close(&family->fd[family->i_fd - 1][0]);
	error_code = execute_cmd(command, family->env);
	perform_illegal_act_on_family(&family);
	ft_close(&fd);
	exit(error_code);
}
