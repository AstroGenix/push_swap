/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:08:41 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/08 12:08:43 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*sptr;
	int		i;

	sptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		sptr[i] = s[i];
		i++;
	}
	sptr[i] = '\0';
	return (sptr);
}

/*
- - Description
The strdup() function returns a pointer to a new string which is a duplicate
of the string s. Memory for the new string is obtained with malloc().
*/

/*
int main()
{
	char *mine = "Remember remember the 5th of November.";
	char *theirs;

	mine = ft_strdup(mine);
	theirs = strdup(mine);
	printf("ft_strdup:%s:\nstrdup   :%s:\n", mine, theirs);

	return 0;
}
*/