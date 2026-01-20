/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:37:21 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 11:28:20 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
# include <stdio.h>
int	main()
{
	int	*value;
	int	i;
	t_list	*new_node;

	i = 15;
	value = i;
	new_node = ft_lstnew(&value);
	printf("%d\n", (int)new_node->content);
	//printf("%d\n", new_node->next);
	free(new_node);
}*/