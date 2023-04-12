/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:09:23 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/02 15:09:25 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;

	if (!dst && !size)
		return (0);
	i = 0;
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && len_dst + 1 < size)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (len_dst + ft_strlen(&src[i]));
}

/*
- - Description
The strlcat() function appends the NUL-terminated string src to the end of dst.
*/

/*
int main (void)
{
	char original[20] = "Do the math!";
	char addon[] = "50 minute ted talk.";
	printf("%ld\n", ft_strlcat(original, addon, 24));
	printf("%s\n%s", original,addon);
	return (0);
}
*/
