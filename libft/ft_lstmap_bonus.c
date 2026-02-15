/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:17:11 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/10 01:04:13 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack_node	*ft_lstmap(t_stack_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack_node	*new_lst;
	t_stack_node	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f((void *)(long)lst->nbr));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
