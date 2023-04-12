/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:08:29 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/08 12:08:31 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
- - Description
The calloc() function allocates memory for an array of nmemb elements of size
bytes each and returns a pointer to the allocated memory.
The memory is set to zero.
If nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
value that can later be successfully passed to free().
*/