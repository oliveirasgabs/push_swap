/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:16:38 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 16:04:31 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next) //Checa se a pilha tá vazia ou se tem 1 nó
		return ;
	last = ft_lstlast(*stack); //Encontra o ultimo nó
	last->prev->next = NULL; //O atributo próximo do nó anterior ao atual será null
	last->next = *stack; //O antigo último elemento aponta o seu próximo para o topo
	last->prev = NULL; //Como ele é o primeiro, não pode ter nada antes dele
	*stack = last; //O ponteiro cabeça agora aponta pro novo primeiro nó
	last->next->prev = last; //O ultimo nó agora aponta para quem tá acima dele
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
