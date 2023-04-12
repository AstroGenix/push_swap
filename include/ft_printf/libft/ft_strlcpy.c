/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:09:14 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:09:15 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	if (size > i)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
- - Description
The strlcpy() function copies up to size - 1 characters from the NUL-terminated
string src to dst, NUL-terminating the result. 
*/

/*
int main (void)
{
	char original[40] = "Do the math!";
	char addon[] = "50 minute ted talk.";
	printf("%d\n", ft_strlcpy(original, addon, 30));
	return (0);
}
*/
