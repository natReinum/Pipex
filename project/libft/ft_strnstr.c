/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:59 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/25 13:10:38 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*search;
	const char	*start;
	size_t		len_start;

	if (!*little)
		return ((char *) big);
	while (*big && len)
	{
		search = little;
		start = big;
		len_start = len;
		while (*big && *search && *big == *search && len_start)
		{
			big++;
			search++;
			len_start--;
		}
		if (!*search)
			return ((char *) start);
		len--;
		big = start + 1;
	}
	return (NULL);
}
