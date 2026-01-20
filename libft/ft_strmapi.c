/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:42:45 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/06 02:42:47 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	size_t	i;
	char	*new_str;

	str_len = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[str_len] = '\0';
	return (new_str);
}
