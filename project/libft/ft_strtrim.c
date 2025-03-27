/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:25:39 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/01 17:55:58 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*get_st(const char *s1, const char *s2)
{
	int	start;
	int	found;
	int	i;

	start = 0;
	while (s1[start])
	{
		found = 0;
		i = 0;
		while (s2[i])
		{
			if (s1[start] == s2[i++])
				found = 1;
		}
		if (!found)
			break ;
		start++;
	}
	return ((char *) s1 + start);
}

static char	*get_end(const char *s1, const char *s2, char *start)
{
	int	found;
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (s1 + i >= start)
	{
		found = 0;
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j++])
				found = 1;
		}
		if (!found)
			break ;
		i--;
	}
	if (s1 + i < start)
		return ((char *) s1);
	return ((char *) s1 + i);
}

static char	*build_string(const char *start, const char *end)
{
	char	*str;
	size_t	i;

	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*start;
	char	*end;
	char	*rtn_str;

	start = get_st(s1, s2);
	end = get_end(s1, s2, start);
	if (!s1[0] || end < start)
	{
		rtn_str = malloc(sizeof(char));
		if (!rtn_str)
			return (NULL);
		rtn_str[0] = '\0';
	}
	else
		rtn_str = build_string(start, end);
	if (!rtn_str)
		return (NULL);
	return (rtn_str);
}
