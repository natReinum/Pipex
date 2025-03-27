/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:25 by nmunier           #+#    #+#             */
/*   Updated: 2024/11/18 15:51:17 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*get_last_rec(t_list *lst)
{
	if (!lst->next)
		return (lst);
	return (get_last_rec(lst->next));
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	return (get_last_rec(lst));
}
