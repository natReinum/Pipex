/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:16:21 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 14:10:29 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils_bonus.h"

static char	*strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

char	*get_input(int fd)
{
	char	buffer[2];
	char	*input;
	int		bytes_read;

	input = NULL;
	buffer[0] = 'n';
	bytes_read = 42;
	while (bytes_read > 0 && buffer[0] && buffer[0] != '\n')
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read < 1)
			continue ;
		buffer[bytes_read] = '\0';
		input = strjoin_free(input, buffer);
	}
	return (input);
}

void	add_command_to_list(t_command **cmd_list, t_command *command)
{
	t_command	*tmp;

	if (!*cmd_list)
		*cmd_list = command;
	else
	{
		tmp = *cmd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = command;
	}
}

void	conceive_forgotten_children(t_family *family, t_command *start, \
									t_command *end)
{
	t_error	error;
	pid_t	pid;

	while (start != end)
	{
		error = success;
		if (pipe(family->fd[family->i_fd]) == -1)
			error = pipe_err;
		pid = fork();
		if (pid == -1)
			error = fork_err;
		if (error != success)
			return ((void)handle_error(&error));
		if (pid == 0)
			execute_middle_child(family, start);
		ft_close(&family->fd[family->i_fd][1]);
		family->i_fd += 1;
		start = start->next;
	}
}

int	assign_outfile_bonus(const char *path, t_family *family)
{
	int	fd;

	if (!family->here_doc)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (access(path, W_OK) == -1)
	{
		ft_close(&fd)
		return (-1);
	}
	return (fd);
}
