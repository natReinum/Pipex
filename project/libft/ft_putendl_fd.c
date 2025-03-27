/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:43:22 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/15 18:11:59 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endline[1];

	endline[0] = '\n';
	if (fd >= 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, &endline, 1);
	}
}
