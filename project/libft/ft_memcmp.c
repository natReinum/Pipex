/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:28:55 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/14 14:26:12 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				cmp;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	while (n--)
	{
		cmp = *s1_ptr - *s2_ptr;
		if (cmp != 0)
			return (cmp);
		s1_ptr++;
		s2_ptr++;
	}
	return (0);
}
