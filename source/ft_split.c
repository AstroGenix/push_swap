/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:53:29 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/10 19:53:31 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	word_count(char *string, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (string[i] != '\0')
	{
		if (string[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (string[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*word_build(const char *str, int start, int finish)
{
	char	*word;
	char	*result;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	result = word;
	free(word);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		j;
	int		start;

	str = (char **)malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			str[j++] = word_build(s, start, i);
			start = -1;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
