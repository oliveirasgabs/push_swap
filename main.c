/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:06:07 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 23:01:30 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void handle_sorting(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		sa(a, false);
	else if (size == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

static char	**parse_arguments(int argc, char *argv[], t_stack_node **a)
{
	char	**matrix;

	matrix = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2 && !argv[1][0])
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	else if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		if (!matrix || !matrix[0])
		{
			if (matrix)
				free_matrix(matrix);
			write(1, "Error\n", 6);
			return (NULL);
		}
		init_stack_a(a, matrix, matrix);
	}
	else
		init_stack_a(a, argv + 1, NULL);
	return (matrix);
}

static void cleanup_resources(t_stack_node *a, char **matrix)
{
	free_stack(&a);
	if (matrix)
		free_matrix(matrix);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**matrix;

	a = NULL;
	b = NULL;
	matrix = parse_arguments(argc, argv, &a);
	if (!stack_sorted(a))
		handle_sorting(&a, &b);
	cleanup_resources(a, matrix);
	return (0);
}
