/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:11:39 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:11:41 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j <= len)
		{
			if (little[j + 1] == '\0')
				return ((char *) big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
- - Description
The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters
are searched. Characters that appear after a \0 character are not searched.
*/


int main(void)
{
	char haystack[] = "The first word is then the second word.";
	char needle[] = "The";
	int size = 40;
	char *ptr = ft_strnstr(haystack, needle, size);
	printf("ft_strnstr - %s\n", ptr);
}
