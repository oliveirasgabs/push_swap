/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:08:09 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 19:41:32 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

/*Helper functions*/
bool		stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

/*Algorithm*/
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);

/*Stack initiation*/
void	init_stack_a(t_stack_node **a, char *argv[], char **matrix);

/*Nodes initiation*/
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);


/*Handle errors*/
bool	error_syntax(char *str);
void	free_errors(t_stack_node **a, char **matrix);
void	free_stack(t_stack_node **stack);
int		error_duplicate(t_stack_node *a, int n);

/*-----Operations-----*/

/*Swaps*/
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

/*Push*/
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);

/*Rotations*/
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);




#endif
