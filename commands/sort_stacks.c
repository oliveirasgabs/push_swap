/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:09:10 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 16:01:20 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a); //pega o nó com menor custo
	if (cheapest_node->above_median && cheapest_node->target_node->above_median) //se o nó tá acima da metade da pilha e o alvo dele tbm
		rotate_both(a, b, cheapest_node); //rotaciona os dois
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) //se o nó tá baixo da metade da pilha e o alvo dele tbm
		rev_rotate_both(a, b, cheapest_node); // faz reverse return de ambos
	prep_for_push(a, cheapest_node, 'a'); //posiciona o nó em A
	prep_for_push(b, cheapest_node->target_node, 'b'); //posiciona o alvo em B
	pb(b, a, false);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while((*a)->nbr != find_min(*a)->nbr)
	{
		current_index(*a);
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b) //função para dar inicio ao algoritmo
{
	int	size_a;

	size_a = ft_lstsize(*a); //verifico o tamanho da lista
	if (size_a-- > 3 && !stack_sorted(*a)) //verifico de estamos em 3, caso seja maior, joga o nó pra pilha b
		pb(b, a, false);
	if (size_a-- > 3 && !stack_sorted(*a)) // verifico novamente, se ainda for maior, jogo de novo pra pilha b
		pb(b, a, false);
	while (size_a-- > 3 && !stack_sorted(*a)) //agora, se ainda não tiver 3 nos sobrando, eu vou precisar mexer de forma organizada
	{
		init_nodes_a(*a, *b); //se cheguei aqui, eu preciso agora organizar os nós e calcular o custo de cada um antes de mover
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
