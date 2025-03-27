/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:17 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/01 18:44:10 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	str[len - 1] = '\0';
	i = 0;
	while (i++ < len)
		str[i - 1] = s[i - 1];
	return (str);
}
