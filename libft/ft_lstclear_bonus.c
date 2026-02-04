/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:32:57 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/03 23:52:51 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack_node **lst, void (*del)(void *))
{
	t_stack_node	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
/*
void	ola(void *content)
{
	return ;
}
#include <stdio.h>

int	main(void)
{
	int	i;
	t_stack_node	*new_node;

	i = 0;
	new_node = NULL;
	while (i < 10)
	{
		ft_lstadd_back(&new_node, ft_lstnew(&i));
		i++;
	}
	ft_lstclear(&new_node, ola);
	if (new_node == NULL)
		printf("Lista deletada com sucesso.");
	else
		printf("Erro ao deletar lista.");
}*/
