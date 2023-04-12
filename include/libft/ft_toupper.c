/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:09:37 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:09:38 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <ctype.h>
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*
- - Description
toupper() converts the letter c to upper case, if possible.
*/

/*
int main(void)
{
	char drow;

	drow = 'a';
	printf("%c - toupper\n%c - ft_toupper\n", toupper(drow), ft_toupper(drow));
}
*/