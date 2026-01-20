/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:56:33 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 10:48:40 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	sub_len;
	char	*str;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	sub_len = str_len - start;
	if (sub_len > len)
		sub_len = len;
	str = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*#include <stdio.h>
int	main(void)
{
	printf("Expected: World | Got: %s\n", ft_substr("Hello World!", 6, 5));
	printf("Expected: b | Got: %s\n", ft_substr("abcdef", 1, 1));
	printf("Expected: 9 | Got: %s\n", ft_substr("0123456789", 9, 10));
	printf("Expected: | Got: %s\n", ft_substr("", 0, 5));
	printf("Expected: | Got: %s\n", ft_substr("Qualquer Coisa", 5, 0));
}
*/
