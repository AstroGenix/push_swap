/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:57 by dberehov          #+#    #+#             */
/*   Updated: 2023/03/14 11:12:59 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Create special cases for:
• When there is a low ammount of numbers;
Test for github
*/

#include "includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	if (check_input(argv) == false) // Check input for abnormalities or duplicates (unique numbers only).
		printf("Something went wrong!");//return (0);
	else
		printf("Sweet!");

	return (0);
}

bool	check_input(char *argv[]) // main - checks input for incorrect values (accepted values are unique positive or negative numbers).
{
	int	i;

	i = 1;
	while (argv[i]) // Loop to check for not numbers.
	{
		if (check_number(argv[i]) == false) // If return is false -> argv[i] wasn't a number.
			return (false);
		i++;
	}
	if (check_duplicates(argv) == true) // Checks for duplicates.
		return (false);
	return (true);
}

bool	check_number(char *argv) // check_input - Checks if input contains only a number.
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0') // Skips positive and negative and check if number follows sign.
		i++;
	while (argv[i])
	{
		if ('0' <= argv[i] && argv[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_duplicates(char *argv[]) // check_input - verifies the input for duplicate values.
{
	int	i;
	int	j;

	i = 1;
	while(argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && dupstring_compare(argv[i],argv[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	dupstring_compare(const char *str1, const char *str2) // check_duplicates - Compares two strings of digits to check if they are the same or not.
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1[i] == '+') //  +1 == 1 but -1 != 1.
	{
		if (str2[j] != '+') // Skips '+' sign if false.
		i++;
	}
	else
	{
		if (str2[j] == '+')
		i++;
	}
	while(str1[i] && str2[j] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[j]); // Return 0 if the strings match.
}

/*static void	list_init(t_list **stack_a, int argc, char *argv[])
{
	t_list	*new;
	int		i;

	i = 0;
	if (argc = 1)
		return (NULL);
	else
		i = 1;
	while (argv[i])
	{
		new = list_newnode(ft_atoi(argv[i]));
		list_addback(stack_a,new);
		i++;
	}
}

// LIBFT LIBRARIES

int list_newnode(int *num)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}
*/