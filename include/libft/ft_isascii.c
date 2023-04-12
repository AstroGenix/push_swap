/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:03:37 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:03:38 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
- - Description
Checks whether c fits into the ASCII character set.
*/

/*
int main(void)
{
	char drow;

	drow = 127;
	printf("%d - isascii\n%d - ft_isascii\n", isascii(drow), ft_isascii(drow));
}
*/
