/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:00:20 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:00:21 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
- - Description
Checks for a digit (0 through 9). 
*/

/*
int main(void)
{
	char drow;

	drow = 50;
	printf("%d - isdigit\n%d - ft_isdigit\n", isdigit(drow), ft_isdigit(drow));
}
*/
