/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:34:49 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/25 12:37:57 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned char	to_ascii(char n)
{
	return ((unsigned char) n);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		comp;

	if (n == 0)
		return (0);
	while (n-- && *s1 && *s2)
	{
		comp = to_ascii(*s1++) - to_ascii(*s2++);
		if (comp != 0)
			return (comp);
	}
	if (n + 1 != 0 && *s1 != *s2)
		return (to_ascii(*s1) - to_ascii(*s2));
	return (0);
}
