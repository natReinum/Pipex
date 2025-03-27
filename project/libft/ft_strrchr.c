/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:19:16 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/13 17:49:47 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	c = c % 256;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s[len] == c)
			return ((char *) &s[len]);
	}
	return (NULL);
}
