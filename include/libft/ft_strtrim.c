/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:56:59 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/08 14:57:00 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>*/

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*newstr;
	size_t		len;
	size_t		i;
	size_t		start;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (is_set(s1[i], set) == 1)
		i++;
	while (is_set(s1[len - 1], set) == 1 && len > i)
		len--;
	newstr = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!newstr)
		return (NULL);
	start = 0;
	while (s1[start + i] != '\0' && start < len - i)
	{
		newstr[start] = s1[start + i];
		start++;
	}
	newstr[start] = '\0';
	return (newstr);
}

/* 03
- - Description
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
specified in ’set’ removed from the beginning and the end of the string.
- - Parameters
s1: The string to be trimmed.
set: The reference set of characters to trim.
- - Return
The trimmed string.
NULL if the allocation fails.
*/

/*int main(void)
{
  char str[] = "Banana";
  printf("Before\n:%s:\nAfter\n:%s:\n",str,ft_strtrim(str, "Ba"));
}*/