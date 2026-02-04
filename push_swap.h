/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:08:09 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/03 21:41:57 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *prev;
	struct s_stack_node *next;
} t_stack_node;

void	init_stack_a(t_stack_node **a, char *argv[]);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
int		error_syntax(char *str);



#endif
