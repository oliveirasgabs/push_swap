/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:15:16 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 15:19:30 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack) //funcao pra verificar se ta ordenado
{
	if (!stack) //se vier null
		return (true);
	while (stack->next) //enquanto não chegar no final da lista
	{
		if (stack->nbr > stack->next->nbr) // se o atual é maior que o numero do proximo nó, então nao ta ordenado
			return (false);
		stack = stack->next; // vai pro prox
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack) //função para encontrar o menor valor
{
	long			min;
	t_stack_node	*min_node;

	if (!stack) //se tiver null
		return (NULL);
	min = LONG_MAX; //o min agr é igual a 2147483647 para 32bits
	while (stack != NULL) // enquanto nao chegou no final da lista
	{
		if (stack->nbr < min) // se o prato atual for menor que o valor que ta valando o min
		{
			min = stack->nbr; //agora o min vai ser o valor do no atual
			min_node = stack; //e o no minimo vai ser esse de agr
		}
		stack = stack->next; //vai pro prox
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack) //função para encontrar o maior valor
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack != NULL)
	{
		if (stack->nbr > max) //Se o valor atual é maior que o valor max
		{
			max = stack->nbr; // Novo valor maximo é o prato atual
			max_node = stack; // o maior nó é o atual
		}
		stack = stack->next;
	}
	return (max_node);
}
