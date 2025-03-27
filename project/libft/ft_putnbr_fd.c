/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:48:45 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/15 18:00:44 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	write_file_rec(unsigned int abs, int power, int fd)
{
	char	c;

	if (power == 0)
		return ;
	c = abs / power + '0';
	abs = abs % power;
	write(fd, &c, 1);
	write_file_rec(abs, power / 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			minus;
	int				power;
	unsigned int	abs;

	if (fd < 0)
		return ;
	power = 1;
	minus = '-';
	if (n < 0)
	{
		write(fd, &minus, 1);
		abs = -n;
	}
	else
		abs = n;
	while (abs / power >= 10)
		power *= 10;
	write_file_rec(abs, power, fd);
}
