/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:10:45 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:10:46 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	while (count >= 0)
	{
		if (*str == c)
			return ((char *) str);
		str--;
		count--;
	}
	return (NULL);
}

/*
- - Description
The strrchr() function returns a pointer to the last occurrence of
the character c in the string s.
*/

/*
int main(void)
{
	char string[] = "Forty-two, the ultimate answer to life.";
	char *first_L1 = strrchr(string, '1');
	printf("strrchr - %s\n", first_L1);
	char *first_L2 = ft_strrchr(string, '1');
	printf("ft_strrchr - %s\n", first_L2);
}
*/
