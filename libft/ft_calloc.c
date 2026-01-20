/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 11:35:25 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/02 17:15:27 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			bytes;

	if (nmemb == 0 || size == 0)
		bytes = 1;
	else if (nmemb > SIZE_MAX / size)
		return (NULL);
	else
		bytes = nmemb * size;
	tmp = malloc(bytes);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, bytes);
	return (tmp);
}
