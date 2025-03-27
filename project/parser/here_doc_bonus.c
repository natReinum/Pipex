/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:06:05 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/27 13:25:38 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/here_doc_bonus.h"

void	read_input(t_family *family, char *limiter)
{
	size_t	limiter_len;
	char	*line;
	int		fd;

	fd = assign_infile_bonus("here_doc", family);
	line = get_input(0);
	limiter_len = ft_strlen(limiter);
	while (line && !(ft_strncmp(line, limiter, limiter_len) == 0 \
			&& ft_strlen(line) - 1 == limiter_len))
	{
		write(fd, line, ft_strlen(line));
		free(line);
		line = get_input(0);
	}
	free(line);
	ft_close(&fd);
}

void	delete_here_doc(t_family *family)
{
	if (!family->here_doc)
		return ;
	if (unlink("here_doc") == -1)
		perror("Error deleting here_doc");
}
