/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:49:22 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/29 16:31:12 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>
#include <utils.h>

int	execute_cmd(t_command *cmd, char **env)
{
	char	*join;
	char	*tmp;
	char	*empty_args[2];

	if (cmd->cmd_path && cmd->cmd_arg)
		execve(cmd->cmd_path, cmd->cmd_arg, env);
	else
	{
		empty_args[0] = "";
		empty_args[1] = NULL;
		execve("", empty_args, env);
	}
	if (cmd->cmd_path)
	{
		tmp = ft_strjoin("failed to execute command '", cmd->cmd_path);
		join = ft_strjoin(tmp, "'");
		perror(join);
		free(join);
		free(tmp);
	}
	else
		perror("command not found (empty)");
	return (127);
}

char	**get_cmd_args(char **cmd_args)
{
	int		i;
	char	*temp;

	if (!cmd_args || !*cmd_args)
		return (ft_free_array(&cmd_args), NULL);
	if (ft_strrchr(cmd_args[0], '/'))
	{
		i = ft_strlen(cmd_args[0]) - 1;
		while (i >= 0 && cmd_args[0][i] != '/')
			i--;
		temp = ft_strdup(cmd_args[0] + i + 1);
		free(cmd_args[0]);
		cmd_args[0] = temp;
	}
	return (cmd_args);
}

void	conceive_better_child(t_family *family, t_command *cmd)
{
	t_error	error;
	pid_t	pid;

	error = success;
	family->fd_in = assign_infile(family->infile);
	if (pipe(family->fd[family->i_fd]) == -1)
		error = pipe_err;
	pid = fork();
	if (pid == -1)
		error = pipe_err;
	if (error != success)
	{
		handle_error(&error);
		return ;
	}
	if (pid == 0)
		execute_first_child(family, cmd);
	ft_close(&family->fd[family->i_fd][1]);
	family->i_fd += 1;
}

void	conceive_less_important_child(t_family *family, t_command *cmd)
{
	t_error	error;
	pid_t	pid;

	error = success;
	pid = fork();
	if (pid == -1)
		error = fork_err;
	if (error != success)
	{
		handle_error(&error);
		return ;
	}
	if (pid == 0)
		execute_last_child(family, cmd);
	family->last_child_pid = pid;
}

int	angry_parent_wait_for_children(t_family *family)
{
	int		exit_status;
	int		status;
	pid_t	pid;

	exit_status = 0;
	pid = 1;
	if (ft_strncmp(family->infile, "/dev/urandom", 13) == 0 \
		|| ft_strncmp(family->infile, "/dev/random", 12) == 0)
		(ft_close(&family->fd_in), ft_close(&family->fd[0][0]), \
			ft_close(&family->fd[0][1]));
	while (pid > 0)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == family->last_child_pid)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	return (exit_status);
}
