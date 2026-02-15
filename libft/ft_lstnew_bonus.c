/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:37:21 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/10 00:59:47 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack_node	*ft_lstnew(void *content)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->nbr = (int)(long)content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
/*
# include <stdio.h>
int	main()
{
	int	*value;
	int	i;
	t_stack_node	*new_node;

	i = 15;
	value = i;
	new_node = ft_lstnew(&value);
	printf("%d\n", (int)new_node->content);
	//printf("%d\n", new_node->next);
	free(new_node);
}*/
