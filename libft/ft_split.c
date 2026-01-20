/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:42:37 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 10:50:56 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static char	**create_line(char **matrix, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	end;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			end = i;
			while (s[end] && s[end] != c)
				end++;
			matrix[j] = ft_substr(s, start, end - start);
			if (!matrix[j])
				return (free_matrix(matrix));
			j++;
			i = end;
		}
		else
			i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	size_matrix;
	char	**result;

	if (s == NULL)
		return (NULL);
	size_matrix = count_words(s, c);
	matrix = (char **)malloc(sizeof(char *) * (size_matrix + 1));
	if (!matrix)
		return (NULL);
	matrix[size_matrix] = NULL;
	result = create_line(matrix, s, c);
	if (result == NULL && size_matrix > 0)
		return (NULL);
	if (size_matrix == 0)
		return (matrix);
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char **matrix = ft_split("oi tudo bem com voce", ' ');

	for (int i = 0; matrix[i]; i++)
	{
		printf("%s\n", matrix[i]);
		free(matrix[i]);
	}
	free(matrix);
}*/
