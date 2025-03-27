/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:10:45 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/15 11:50:24 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*mem_ptr;
	size_t				total;
	unsigned long long	max;

	max = 4294967295;
	if (size && nmemb > max / size)
		return (NULL);
	total = nmemb * size;
	mem_ptr = malloc(total);
	if (!mem_ptr)
		return (NULL);
	ft_bzero(mem_ptr, total);
	return (mem_ptr);
}
