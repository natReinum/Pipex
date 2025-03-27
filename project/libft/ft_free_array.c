/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:13:17 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 14:16:53 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char ***array)
{
	char	**tmp;

	if (!array)
		return ;
	tmp = *array;
	while (tmp && *tmp)
		free(*tmp++);
	free(*array);
	*array = NULL;
}
