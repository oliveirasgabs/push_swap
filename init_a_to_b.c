/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:21:01 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 15:08:36 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack) //função para colcoar qual index de cada nó e se eles estão acima ou abaixo da metade da lista
{
	int	i;
	int	median;

	i = 0;
	if(!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) //para cada nó na pilha A, eu vou calcular o melhor alvo
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a) //enquanto nao chegar no final da pilha
	{
		best_match_index = LONG_MIN; //menor valor
		current_b = b;
		while (current_b) //enquanto nao chegar no final
		{
			//se o valor do nó atual for menor que o valor do no a e o valor do nó atual for maior que o menor valor possivel
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr; //agora o menor valor possivel é o valor atual
				target_node = current_b; //e o alvo vai ser o no atual
			}
			current_b = current_b->next; //vai pro proximo
		}
		if (best_match_index == LONG_MIN) //se nao encontrou nada
			a->target_node = find_max(b); //verifico de encontro o maior valor
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) // calculo para saber o custo de movimentar
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);

	while(a)
	{
		a->push_cost = a->index; //o custo a principio é o index
		if (!a->above_median) //se o nó estiver abaixo do meio
			a->push_cost = size_a - (a->index); //o custo dele será o tamanho da pilha menos o index dele
		if (a->target_node->above_median) //se o alvo do nó atual tiver acima do meio da pilha
			a->push_cost += a->target_node->index; //o custo vai ser a soma do custo atual + o indice do alvo dele
		else
			a->push_cost += size_b - (a->target_node->index); // o custo vai ser a soma do custo + tamanho da pilha b - o indice do alvo do nó atual
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack) //verifica se o nó atual de fato tem o menor custo
{
	long	cheapest_value;
	t_stack_node	*cheapest_node;

	if(!stack)
		return ;
	cheapest_value = LONG_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->push_cost < cheapest_value) //se o custo do nó atual for menor que o menor valor atual
		{
			cheapest_value = stack->push_cost; //o menor valor atual vai ser o custo do nó atual
			cheapest_node = stack; // e o menor nó vai ser o atual
		}
		stack = stack->next; //vai pro proximo
	}
	cheapest_node->cheapest = true; //o nó que for o menor, agora será true
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //função para setar os calculos de movimento de cada nó
{
	current_index(a); //função para verificar a posição do no atual a
	current_index(b); //função para verificar a posição do no atual b
	set_target_a(a, b); //para cada nó na pilha A, eu vou verificar o nó alvo
	cost_analysis_a(a, b);
	set_cheapest(a);
}
