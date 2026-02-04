/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:11:21 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/03 23:51:39 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	int	*value;
	int	i;
	t_stack_node	*new_node;

	i = 0;
	value = i;
	new_node = NULL;
	while (i < 10)
	{
		ft_lstadd_back(&new_node, ft_lstnew(i));
		i++;
	}
	for (int j = 0; j < 10; j++)
	{
		printf("%d\n", (int)new_node->content);
		new_node = new_node->next;
	}
}*/
