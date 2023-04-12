/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:00:06 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:00:08 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if (c >= 'A' && (c <= 'Z' || c >= 'a') && c <= 'z')
		return (1);
	return (0);
}

/*
- - Description
Checks for an alphabetic character.
*/

/*int main(void)
{
	char drow;

	drow = 65;
	printf("%d - isalpha\n%d - ft_isalpha\n", isalpha(drow), ft_isalpha(drow));
}*/
