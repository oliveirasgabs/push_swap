/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:12:17 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/04 15:34:29 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	size;

	size = ft_strlen(s);
	tmp = (char *)malloc(size + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s, size + 1);
	return (tmp);
}
