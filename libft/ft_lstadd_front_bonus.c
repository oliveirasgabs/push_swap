/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:07:32 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 14:54:38 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
	{
		new = *lst;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	int	*value;
	int	i;
	t_list	*new_node;

	i = 0;
	value = i;
	new_node = NULL;
	while (i < 10)
	{
		ft_lstadd_front(&new_node, ft_lstnew(i));
		i++;
	}
	for (int j = 0; j < 10; j++)
	{
		printf("%d\n", (int)new_node->content);
		new_node = new_node->next;
	}
}*/