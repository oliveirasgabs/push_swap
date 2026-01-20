/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:06:07 by gabrioli          #+#    #+#             */
/*   Updated: 2026/01/20 18:49:44 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2 || (argc == 2 && !argv[1])) //Se o programa tem < de 1 argumento ou se são dois argumentos e o segundo argumento é nulo
		return (1); // Caso seja, retornar 1;
	else if (argc == 2) //Verificar se só tem 2 argumentos
	{
		argv = ft_split(argv[1], ' '); //chama afunção split para separar o argv[1]
		//Depois de splitar, nós devemos percorrer a matriz
			//transformar em atol (alnum to long) cada casinha
			//mallocar um "prato" com aquele número na stack "a";
	}//
}
