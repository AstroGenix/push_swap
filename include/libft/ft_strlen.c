/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:15 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:04:16 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
- - Description
The strlen() function calculates the length of the string s,
excluding the terminating null byte-
*/

/*
int main()
{
	char arr[] = "0123456789";
	printf("ft_strlen - %d\n", ft_strlen(arr));
	printf("strlen - %d\n", strlen(arr));
}
*/
