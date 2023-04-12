/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:11:07 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:11:09 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_s;
	unsigned char	chr_c;

	i = 0;
	str_s = (unsigned char *) s;
	chr_c = (unsigned char) c;
	while (i < n)
	{
		if (*str_s == chr_c)
			return (str_s);
		str_s++;
		i++;
	}
	return (NULL);
}

/*
- - Description
The memchr() function scans the initial n bytes of the memory area pointed to by
s for the first instance of c. Both c and the bytes of the memory area pointed
to by s are interpreted as unsigned char. 
*/

/*
int main(void)
{
	char chr_array[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	char *pos = ft_memchr(chr_array, 'c', 3);

	if (pos == NULL)
		printf("Character not found.\n");
	else
	{
		printf("pos[0] = %c\n", pos[0]);
		printf("pos[1] = %c\n", pos[1]);
	}

//example 2

	char str[] = "dberehov@student.42porto.com";

	char *domain = ft_memchr(str, '@', strlen(str));

	printf("domain: %s\n", domain);
}
*/
