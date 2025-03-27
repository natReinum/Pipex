/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:56:24 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/18 16:04:06 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	apply_f_rec(t_list *cell, void (*f)(void *))
{
	if (!cell)
		return ;
	f(cell->content);
	apply_f_rec(cell->next, f);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	apply_f_rec(lst, f);
}
