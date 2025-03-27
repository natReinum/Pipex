/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:07:37 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/12 17:17:50 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t		len;
	char		*d_ptr;
	const char	*s_ptr;

	d_ptr = dst;
	s_ptr = src;
	len = ft_strlen(src);
	if (siz > 0)
	{
		while (*s_ptr && --siz)
			*d_ptr++ = *s_ptr++;
		*d_ptr = '\0';
	}
	return (len);
}
