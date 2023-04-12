/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:07:57 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:08:46 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
- - Description
The memmove() function copies n bytes from memory area src to memory area dest.
*/

/*
int main(void)
{
	int source[10] = {1,2,3,4,5,6,7,8,9,10};
	int destination[10];

	ft_memmove(source+2, source, sizeof(int) * 8);

	for (int i = 0; i < 10; i++)
	{
		printf("source[%d]=%d\n", i, source[i]);	
	}

	return (0);
}
*/