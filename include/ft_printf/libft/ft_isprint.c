/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:04 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:04:06 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
- - Description
Checks for any printable character including space.
*/

/*
int main(void)
{
	char drow;

	drow = 126;
	printf("%d - isprint\n%d - ft_isprint\n", isprint(drow), ft_isprint(drow));
}
*/
