/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:50:05 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/09 23:50:06 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

int	word_count(char *string, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (string[i] != '\0')
	{
		if (string[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (string[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char	*word_build(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		start;

	str = (char **)malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			str[j++] = word_build(s, start, i);
			start = -1;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

/* 04
- - Description
Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end
with a NULL pointer.
- - Parameters
s: The string to be split.
c: The delimiter character.
- - Return
The array of new strings resulting from the split.
NULL if the allocation fails.
*/

/*
int main()
{
    char *str = "AXBBXCCCXDDXE";
    char **array = ft_split(str, 'X');
    printf("START\n");
    for (int i = 0; i < 5; ++i)
    {
	    printf(":%s:\n",array[i]);
    }
    printf("END");
}
*/