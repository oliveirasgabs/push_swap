/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:48:07 by gabrioli          #+#    #+#             */
/*   Updated: 2026/01/21 00:08:16 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a); //chama pra procurar o maior nó
	if (biggest_node == *a) //se o maior ta igual ao primeiro no
		ra(a, false); // faz uma rotação em a pra jogar ele pro final
	else if ((*a)->next == biggest_node) //verifica se o proximo é igual ao maior
		rra(a, false); // ai faz o reverse rotation em a
	if ((*a)->nbr > (*a)->next->nbr) // verifica de o conteudo do no atual é maior do que o do proximo
		sa(a, false); //faz swap
}
