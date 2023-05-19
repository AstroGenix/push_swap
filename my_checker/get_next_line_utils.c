/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:18:21 by dberehov          #+#    #+#             */
/*   Updated: 2022/12/05 18:18:22 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This C file will contain all the necessary helper functions used in
'get_next_line' project.
*/

#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_string;
	int		length_s1;
	int		i;

	if (!s1)
		return (NULL);
	length_s1 = ft_strlen(s1);
	new_string = malloc(sizeof(char) * (length_s1 + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[length_s1] = s2[i];
		i++;
		length_s1++;
	}
	new_string[length_s1] = '\0';
	return (new_string);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*string_find;

	string_find = (unsigned char *) s;
	while (*string_find != '\0')
	{
		if (*string_find == c)
			return ((char *) string_find);
		string_find++;
	}
	if (c == 0)
		return ((char *)string_find);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	bzero(ptr, nmemb * size);
	return (ptr);
}
