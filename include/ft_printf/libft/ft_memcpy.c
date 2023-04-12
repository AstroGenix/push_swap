/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:07:04 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:07:07 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*chr_dest;
	char			*chr_src;

	if (!dest && !src)
		return (NULL);
	chr_dest = (char *) dest;
	chr_src = (char *) src;
	i = 0;
	while (i < n)
	{
		chr_dest[i] = chr_src[i];
		i++;
	}
	return (chr_dest);
}

/*
- - Description
The memcpy() function copies n bytes from memory area src to memory area dest.
The memory areas must not overlap. Differs from strcpy() by copying
even null char.
*/

/*
int main(void)
{
	char src[] = "Please forward this to upper management.";
	char dest[100];

	char *dest_ptr = ft_memcpy(dest, src, 0);
	printf("- - - - Before\n");
	printf("src:  %s\n", src);
	printf("dest: %s\n", dest);

	ft_memcpy(dest, src, strlen(src) + 1);

	printf("\n- - - - After\n");
	printf("src:  %s\n", src);
	printf("dest: %s\n", dest);

	printf("\n- - - - Memory adress comparison\n");
	printf("dest_ptr: %p\n", dest_ptr);
	printf("dest:     %p\n", dest);

	printf("\n- - - - Other test\n");
	double src_array[3] = {1.2, 3.4, 5.6};
	double dest_array[3];

	ft_memcpy(src_array+2, src_array, sizeof(src_array));

	for (int i = 0; i < 3; i++)
		printf("dest_array[%d] = %f\n", i, src_array[i]);

	return (0);
}
*/
