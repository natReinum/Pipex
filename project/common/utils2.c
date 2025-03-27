/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:30:36 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/27 18:56:02 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <libft.h>

t_command	*get_list_last(t_command *command)
{
	if (!command)
		return (NULL);
	while (command->next)
		command = command->next;
	return (command);
}

int	assign_infile(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (access(path, R_OK) == -1)
	{
		ft_close(&fd);
		return (handle_error(&(t_error){infile_fd_err}), -1);
	}
	return (fd);
}

int	assign_outfile(const char *path)
{
	int	fd;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (access(path, W_OK) == -1)
	{
		ft_close(&fd);
		return (handle_error(&(t_error){infile_fd_err}), -1);
	}
	return (fd);
}

void	fill_fd_array(t_family *family)
{
	int	i;

	i = 0;
	while (i < family->i_fd_max)
	{
		family->fd[i][0] = -1;
		family->fd[i][1] = -1;
		i++;
	}
}
