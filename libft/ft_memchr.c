/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 01:03:48 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 10:46:00 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*string;
	char		tmp;
	size_t		i;

	string = (const char *)s;
	tmp = (char)c;
	i = 0;
	while (i < n)
	{
		if (string[i] == tmp)
			return ((char *)&string[i]);
		i++;
	}
	return (NULL);
}
