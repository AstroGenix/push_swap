/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:49:29 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/11 19:49:31 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 06
- - Description
Applies the function ’f’ to each character of the string ’s’, and passing its
index as first argument to create a new string (with malloc(3)) resulting 
from successive applications of ’f’.
- - Parameters
s: The string on which to iterate.
f: The function to apply to each character.
- - Return
The string created from the successive applications of ’f’.
Returns NULL if the allocation fails
*/