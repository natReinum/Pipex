/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:00 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/14 11:57:44 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	s_size;
	size_t	d_size;
	size_t	i;

	s_size = ft_strlen(src);
	d_size = ft_strlen(dst);
	if (siz <= d_size)
		return (siz + s_size);
	i = 0;
	while (src[i] && d_size + i < siz - 1)
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}
