/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrioli <gabrioli@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:42:57 by gabrioli          #+#    #+#             */
/*   Updated: 2025/11/07 01:06:56 by gabrioli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*set_str(int nb_len)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (nb_len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	size_t	nb_len;
	size_t	i;
	char	*str;
	long	number;

	number = (long)n;
	nb_len = count_digits(number);
	str = set_str(nb_len);
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	i = nb_len - 1;
	while (number != 0)
	{
		str[i] = ((number % 10) + '0');
		number = number / 10;
		i--;
	}
	str[nb_len] = '\0';
	return (str);
}
/*#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(21474836487));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
}*/
