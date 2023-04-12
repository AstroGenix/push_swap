/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:38 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:04:39 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, 0, n);
}

/*
- - Description
The bzero() function sets the first n bytes of the area starting at s to zero.
*/

/*
int main(void)
{
	char buffer[] = "12345678900000000";

	printf(":%s:\n", buffer);
	ft_bzero(buffer, 1);
	printf(":%s:\n", buffer);
	return (0);
}
*/