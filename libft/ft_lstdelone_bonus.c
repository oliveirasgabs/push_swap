/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:23:15 by gabrioli          #+#    #+#             */
/*   Updated: 2026/02/10 01:00:16 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_stack_node *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del((void *)(long)lst->nbr);
	free(lst);
}
