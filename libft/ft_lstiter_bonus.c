/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:02:22 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/03 23:53:32 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack_node *lst, void (*f)(void *))
{
	t_stack_node	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->nbr);
		tmp = tmp->next;
	}
}
/*
#include <stdio.h>

void	ola(void **content)
{
	(int)(*content)++;
}
int	main(void)
{
	int	i;
	t_stack_node	*new_node;
	t_stack_node	*head;

	i = 0;
	new_node = NULL;
	while (i < 3)
	{
		ft_lstadd_back(&new_node, ft_lstnew(i));
		i++;
	}
	head = new_node;
	printf("Before function:\n");
	for (int j = 0; j < 3; j++)
	{
		printf("%d\n", (int)new_node->content);
		new_node = new_node->next;
	}
	new_node = head;
	ft_lstiter(head, ola);
	//new_node = head;
	printf("After function:\n");
	for (int k = 0; k < 3; k++)
	{
		printf("%d\n", (int)new_node->content);
		new_node = new_node->next;
	}
	return (0);
}*/
