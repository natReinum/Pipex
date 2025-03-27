/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:25:53 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/15 16:19:41 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_words_count(const char *s, char c)
{
	size_t			count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
			continue ;
		}
		s++;
	}
	return (count);
}

static int	fill_array(char **ptr_arr, const char *s, char c, size_t max)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (max--)
	{
		while (s[end] && s[end] != c)
			end++;
		if (end - start > 0)
		{
			*ptr_arr = ft_substr(s, start, end - start);
			if (!*ptr_arr++)
				return (0);
		}
		else
			max++;
		start = ++end;
	}
	return (1);
}

static void	free_array(char ***array)
{
	char	**arr;

	arr = *array;
	while (*arr)
		free(*arr++);
	free(*array);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;

	if (!s)
		return (NULL);
	count = get_words_count(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	if (!fill_array(arr, s, c, count))
	{
		free_array(&arr);
		return (NULL);
	}
	return (arr);
}
