/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:13:51 by gabrioli          #+#    #+#             */
/*   Updated: 2025/10/29 20:31:30 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	letter;
	char	*pointer;

	letter = (char)c;
	pointer = NULL;
	while (*s)
	{
		if (*s == letter)
			pointer = (char *)s;
		s++;
	}
	if (*s == letter)
		pointer = (char *)s;
	return (pointer);
}
