/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:08:09 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/04 01:40:26 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
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
void	current_index(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void	sort_three(t_stack_node **a);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
t_stack_node	*get_cheapest(t_stack_node *stack);
bool	error_syntax(char *str);
void	free_errors(t_stack_node **a);
int		error_duplicate(t_stack_node *a, int n);

/*Operations*/

/*Swaps*/
void	sa(t_stack_node **a, bool print);

/*Rotations*/
void	ra(t_stack_node **a, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	rra(t_stack_node **a, bool print);



#endif
