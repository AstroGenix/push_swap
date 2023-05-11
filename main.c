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

#include "include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;
	char	**split;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
			error(NULL, NULL);
	}
	else
		split = argv;
	if (check_input(split) == false) // Check input for abnormalities or duplicates (unique numbers only).
		error(NULL, NULL);
	b = NULL;
	a = insert_values(argc, split);
	stack_size = fetch_stack_size(a);
	rank_values(a, stack_size + 1);
	if (!is_sorted(a))
		which_sort(&a,&b,stack_size);
	// Free both stacks.
	free_stack(&a);
	free_stack(&b);
	return (0);
}

// Will rank the values in stack A to make it easier to order. (ranked top (stack_size) to bottom (1))
void	rank_values(t_stack *a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*top;
	int		value;

	while (--stack_size > 0)
	{
		ptr = a; // Initialize ptr to head of the stack.
		value = INT_MIN; // Smallest possible integer.
		top = NULL; // Used to track top number.
		while (ptr)
		{
			if (ptr->num == INT_MIN && ptr->rank == 0)
				ptr->rank = 1;
			if (ptr->num > value && ptr->rank == 0) // Get top number and reset small loop.
			{
				value = ptr->num;
				top = ptr;
				ptr = a;
			}
			else
				ptr = ptr->next;
		}
		if (top != NULL)
			top->rank = stack_size;
	}
}

/*
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	if (check_input(argv) == false) // Check input for abnormalities or duplicates (unique numbers only).
		error(NULL, NULL);
	b = NULL;
	a = insert_values(argc, argv);
	stack_size = fetch_stack_size(a);
	rank_values(a, stack_size + 1);
	if (!is_sorted(a))
		which_sort(&a,&b,stack_size);
	// Free both stacks.
	free_stack(&a);
	free_stack(&b);
	return (0);
}
So finally this works like intended meaning ./push_swap.a 3 2 1 works.
The problem is if i put it all as if it all one string like ./push_swap "3 2 1" it will not work.
I understand it reads the input as one string and that I should use ft_split function to separate the ' '.
How would I go about doing that.
*/
