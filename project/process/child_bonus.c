/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:47:30 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 14:16:16 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/process_bonus.h"

void	execute_first_child(t_family *family, t_command *command)
{
	int	fd;

	ft_close(&family->fd[0][0]);
	fd = assign_infile(family->infile);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2 - STDIN");
		ft_close(&fd);
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	if (dup2(family->fd[0][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 - STDOUT");
		ft_close(&fd);
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	execute_cmd(command, family->env);
	perform_illegal_act_on_family_2(&family, 0, 1);
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
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	fd = assign_outfile(family->outfile);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 - STDOUT");
		ft_close(&fd);
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	ft_close(&family->fd[family->i_fd - 1][0]);
	error_code = execute_cmd(command, family->env);
	perform_illegal_act_on_family_2(&family, 0, 1);
	ft_close(&fd);
	exit(error_code);
}

void	execute_middle_child(t_family *family, t_command *command)
{
	if (dup2(family->fd[family->i_fd - 1][0], STDIN_FILENO) == -1)
	{
		perror("dup2 mid - STDIN");
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	if (dup2(family->fd[family->i_fd][1], STDOUT_FILENO) == -1)
	{
		perror("dup2 mid - STDOUT");
		perform_illegal_act_on_family_2(&family, 0, 1);
		exit(-42);
	}
	ft_close(&family->fd[family->i_fd - 1][0]);
	ft_close(&family->fd[family->i_fd - 1][1]);
	ft_close(&family->fd[family->i_fd][0]);
	ft_close(&family->fd[family->i_fd][1]);
	execute_cmd(command, family->env);
	perform_illegal_act_on_family_2(&family, 0, 1);
	exit(0);
}
