/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:48:32 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/18 15:55:11 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	clear_rec(t_list *cell, void (*del)(void *))
{
	if (!cell)
		return ;
	clear_rec(cell->next, del);
	ft_lstdelone(cell, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	clear_rec(*lst, del);
	*lst = NULL;
}
