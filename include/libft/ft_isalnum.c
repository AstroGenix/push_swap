/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:03:15 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:03:17 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && (c <= 90 || c >= 97) && c <= 122))
		return (1);
	return (0);
}

/*
- - Description
Checks for an alphanumeric character.
*/

/*
int main(void)
{
	char drow;

	drow = 50;
	printf("%d - isalnum\n%d - ft_isalnum\n", isalnum(drow), ft_isalnum(drow));
}
*/
