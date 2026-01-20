/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:07:20 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/06 02:44:33 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char)c;
	while (*s)
	{
		if (*s == letter)
			return ((char *)s);
		s++;
	}
	if (*s == letter)
		return ((char *)s);
	return (NULL);
}
