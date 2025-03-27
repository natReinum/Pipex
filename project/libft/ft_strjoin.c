/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:16:23 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/14 17:20:32 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*get_start(const char *s1, const char *s2)
{
	if (!*s1)
		return ((char *) s2);
	return ((char *) s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	char	*str_copied;

	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	str_copied = get_start(s1, s2);
	str[s1_len + s2_len] = '\0';
	ft_memset(str, '3', s1_len + s2_len);
	while (*str++)
	{
		*(str - 1) = *str_copied++;
		if (!*str_copied)
			str_copied = (char *) s2;
	}
	return (str - s1_len - s2_len - 1);
}
