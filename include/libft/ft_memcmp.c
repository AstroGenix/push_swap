/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:11:21 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:11:22 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	i = 0;
	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;
	while (i != n)
	{
		if (str_s1[i] != str_s2[i])
			return (str_s1[i] - str_s2[i]);
		i++;
	}
	return (0);
}

/*
- - Description
The memcmp() function returns an integer less than, equal to, or greater than
zero if the first n bytes of s1 is found, respectively, to be less than,
to match, or be greater than the first n bytes of s2.
*/

/*
int main(void)
{
	char array1[] = "abcdef";
	char array2[] = "abcdef";

	if (ft_memcmp(array1, array2, sizeof(char) * 6) == 0)
	{
		printf("Arrays are the same.\n");
		printf("Arr1: %s | Arr2: %s\n", array1, array2);
	}
	else
	{
		printf("Arrays are different.\n");
		printf("Arr1: %s | Arr2: %s\n", array1, array2);
	}
	printf("Difference: %d", ft_memcmp(array1, array2, sizeof(char) * 6));
}
*/