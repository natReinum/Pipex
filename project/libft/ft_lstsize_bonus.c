/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:50:05 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/18 15:03:01 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	lst_parser_rec(t_list *lst, int depth)
{
	if (!lst)
		return (depth);
	return (lst_parser_rec(lst->next, depth + 1));
}

int	ft_lstsize(t_list *lst)
{
	return (lst_parser_rec(lst, 0));
}
