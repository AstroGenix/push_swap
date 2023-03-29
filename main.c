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

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	if (check_input(argv) == false) // Check input for abnormalities or duplicates (unique numbers only).
		return (0);

	return (0);
}

bool	check_input(char *argv[]) // main - checks input for incorrect values (accepted values are unique positive or negative numbers)
{
	int i;
	int	errors;

	i = 1;
	errors = 0;
	while (argv[i])
	{
		if (!check_number(argv[i]))
			errors++;
		i++;
	}
	if (errors == 0 && check_duplicates(argv) == 0)
		return (true);
	else
		return (false);
}

bool	check_number(char *argv[])
{

}

int	check_duplicates(char *argv[]) // check_input - verifies the input for duplicate values.
{

}

static void	list_init(t_list **stack_a, int argc, char *argv[])
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
