/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:10:56 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:10:57 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
- - Description
The strcmp() function compares the first n bytes of strings s1 and s2.
*/

/*
int main(void)
{
	char one[] = "Fire5";
	char two[] = "Fire";
	int res;
	int ser;

	res = strncmp(one, two, 5);
	ser = ft_strncmp(one, two, 5);
	printf("strncmp - %d\nft_strncmp - %d\n", res, ser);
}
*/