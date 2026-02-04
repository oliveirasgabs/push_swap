/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:30:51 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/03 21:41:21 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if (str[i] == '+' || str[i] == '-' && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (str[i++])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}
