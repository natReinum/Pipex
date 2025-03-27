/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:25 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/25 12:23:05 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d_ptr;
	char	*s_ptr;

	if (!src && !dest)
		return (NULL);
	d_ptr = (char *) dest;
	s_ptr = (char *) src;
	if (d_ptr < s_ptr)
	{
		while (n--)
			*d_ptr++ = *s_ptr++;
	}
	else
	{
		while (n--)
			d_ptr[n] = s_ptr[n];
	}
	return (dest);
}
