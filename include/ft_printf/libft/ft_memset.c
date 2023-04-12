/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:25 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:04:27 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chr_s;

	i = 0;
	chr_s = (unsigned char *) s;
	while (i < n)
	{
		chr_s[i] = c;
		i++;
	}
	return (s);
}

/*
- - Description
The memset() function fills the first n bytes of the memory area pointed
to by s with the constant byte c.
*/

/*
int main(void)
{
	char buffer[10];

	memset(buffer, 'a', sizeof(char) * 10);
	for (int i = 0; i < 10; ++i)
		printf("%c", buffer[i]);
	printf("\n");
	ft_memset(buffer, 'b', sizeof(char) * 10);
	for (int i = 0; i < 10; ++i)
		printf("%c", buffer[i]);
	printf("\n");
	memset(buffer, 'c', sizeof(char) * 10);
	for (int i = 0; i < 10; ++i)
		printf("%c", buffer[i]);
	printf("\n");
	return (0);
}
*/
