/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:23:56 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/08 14:23:57 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len_s1;
	int		i;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	newstr = malloc(sizeof(char) * (len_s1 + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[len_s1] = s2[i];
		i++;
		len_s1++;
	}
	newstr[len_s1] = '\0';
	return (newstr);
}

/* 02
- - Description
Allocates (with malloc(3)) and returns a new string, which is the result of
the concatenation of ’s1’ and ’s2’.
- - Parameters
s1: The prefix string.
s2: The suffix string.
- - Return
The new string.
NULL if the allocation fails.
*/

/*
int main()
{
    char *s1 = "Hakuna";
    char *s2 = "Matata";
    printf("S1 - :%s:\nS2 - :%s:\nS3 - :%s:\n", s1, s2, ft_strjoin(s1, s2));
}
*/
