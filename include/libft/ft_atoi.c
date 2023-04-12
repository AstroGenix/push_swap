/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:11:55 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:11:57 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ngtv;
	int	result;

	i = 0;
	ngtv = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			ngtv = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	return (result * ngtv);
}

/*
- - Description
The atoi() function converts the initial portion of the string pointed to
nptr to int.
*/

/*
int main(void)
{
	char str[] = "++47";
	printf("%d - atoi\n%d - ft_atoi\n", atoi(str), ft_atoi(str));
}
*/
