/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:19:36 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/25 12:21:05 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!src && !dest)
		return (NULL);
	src_ptr = src;
	dest_ptr = dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}
