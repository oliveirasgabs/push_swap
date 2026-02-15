/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:36:16 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 16:05:13 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next) //Se está vazia ou só tem 1 nó, não tem o que fazer
		return ;
	last_node = ft_lstlast(*stack); // Encontra o último nó
	last_node->next = *stack; // O próximo do ultimo nó será a cabeça atual
	*stack = (*stack)->next; // Agora a cabeça será o segundo nó
	(*stack)->prev = NULL; // Limpamos o anterior da nova cabeça (como ele é primeiro, nao pode ter nada antes)
	last_node->next->prev = last_node; // O nó que saiu do topo agora tem o antigo ultimo como seu anterior
	last_node->next->next = NULL; //Agora o nó que tá no fundo tem o seu proximo como null

}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}
