/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:08:36 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/13 16:14:15 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	val;

	val = (unsigned char) c;
	s_ptr = (unsigned char *) s;
	while (n--)
	{
		if (*s_ptr == val)
			return ((void *) s_ptr);
		s_ptr++;
	}
	return (NULL);
}
