/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:49:18 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/11 19:49:20 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_count(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	else if (i == 0)
		count = 1;
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	num;

	num = n;
	i = num_count(num);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[i--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

/* 05
- - Description
Allocates (with malloc(3)) and returns a string representing the integer
received as an argument.
Negative numbers must be handled.
- - Parameters
n: the integer to convert.
- - Return
The string representing the integer.
NULL if the allocation fails.
*/

/*
int	main(void)
{
		printf(":%s:\n", ft_itoa(-12));
}*/
