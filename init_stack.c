/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:43:16 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 19:41:11 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack_node **stack, int n) //função pra criar o nó
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack) //se stack vier nula
		return	; //sai
	node = malloc(sizeof(t_stack_node)); //aloca o que precisa no nó
	if (!node)
		return ; //sai
	node->next = NULL;
	node->nbr = n;
	node->cheapest = 0;
	if (!(*stack)) //se tem o endereço da pilha, mas ela não aponta pra nada, ou seja primeira chamada
	{
		*stack = node; //agora a cabeça recebe o nó
		node->prev = NULL; // e o anterior é nulo pq é a primeira chamada
	}
	else
	{
		last_node = ft_lstlast(*stack); //procura o ultimo nó da pilha
		last_node->next = node; // o ultimo aponta pro nó que criamos agr
		node->prev = last_node; // e o anterior do que criamos será o ultimo
	}
}

void	init_stack_a(t_stack_node **a, char *argv[], char **matrix) //função para iniciar a pilha a
{
	long	n;
	int		i;

	i = 0;
	while (argv[i]) //enquanto não chegar no final do argumento
	{
		if (error_syntax(argv[i])) //verifico se tem algum erro/tem coisas além de número
			free_errors(a, matrix); // libera
		n = ft_atol(argv[i]); // faço conversão para long pq é maior que int
		if (n > INT_MAX || n < INT_MIN) //se estourar,
			free_errors(a, matrix); //libera
		if (error_duplicate(*a, (int)n)) //se tiver duplicado
			free_errors(a, matrix); //libera
		append_node(a, (int)n); //passou em tudo, cria o nó na pilha
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
