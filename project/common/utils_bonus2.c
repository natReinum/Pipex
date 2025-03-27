/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:29:58 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 19:40:53 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils_bonus.h"

int	assign_infile_bonus(const char *path, t_family *family)
{
	int	fd;

	if (!family->here_doc)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (access(path, R_OK) == -1 \
		|| (family->here_doc && access(path, W_OK) == -1))
	{
		if (fd != -1)
			ft_close(&fd);
		return (-1);
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
