/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:06:07 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/15 17:43:17 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL; //Preciso iniciar null pois é boa pratica
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0])) //Se o programa tem < de 1 argumento ou se são dois argumentos e o segundo argumento é nulo
		return (1); // Caso seja, retornar 1;
	else if (argc == 2) //Verificar se só tem 2 argumentos
	{
		argv = ft_split(argv[1], ' '); //chama afunção split para separar o argv[1]
		init_stack_a(&a, argv); // Agora argv aponta pro array de split, sem o nome do programa
	}
	else
		init_stack_a(&a, argv + 1); // Aqui argv ainda é o argv original, então argv + 1 pula o nome
	if (!stack_sorted(a)) //Se não tiver organizado
	{
		if (ft_lstsize(a) == 2) //verifica que a lista só tem 2 pratos
			sa(&a, false); //sort a
		else if (ft_lstsize(a) == 3) // se tiver 3 pratos
			sort_three(&a); //ordena em 3
		else
			sort_stacks(&a, &b); //se tiver mais, chama a função maneira
	}
	free_stack(&a); //tchau tchau lista
	return (0);
}
