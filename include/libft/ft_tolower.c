/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:09:50 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:09:51 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*
- - Description
tolower() converts the letter c to lower case, if possible.
*/

/*
int main(void)
{
	char drow;

	drow = 'B';
	printf("%c - tolower\n%c - ft_tolower\n", tolower(drow), ft_tolower(drow));
}
*/