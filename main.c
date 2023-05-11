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

// Helper function 
static int arr_size(char **arr)
{
	int i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		stack_size;
	char	**split;
	int		len;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	else if (argc == 2)
		split = ft_split(argv[1], ' ');
	else
		error(NULL, NULL);
	if (check_input(split) == false) // Check input for abnormalities or duplicates (unique numbers only).
		error(NULL, NULL);
	len = arr_size(split);
	a = insert_values(len, split);
	b = NULL;
	stack_size = fetch_stack_size(a);
	rank_values(a, stack_size);
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
The part that works is like this.
./push_swap 3 2 1 -> works as intended, argv[0] = './push_swap' argv[1] = 3
This is what my code was doing and it was working still is. However problem arrives if I have
to do something like ./push_swap "3 2 1" which should also work however it goes through a split func
that turns it into argv[0] = 3 argv[1] = 2.
And so there is a missmatch.

./push_swap 3 2 1     | ./push_swap "3 2 1"
argv[0]='./push_swap' | goes into ft_split
argv[1]='3'           |argv[0]='3'
argv[2]='2'           |argv[1]='2'
argv[3]='1'           |argv[2]='1'
*/
