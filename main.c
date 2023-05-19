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
// Good old strlen.
size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// The main function.
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	check_input(argv);
	a = insert_values(argc, argv);
	b = NULL;
	rank_values(a, fetch_stack_size(a) + 1);
	which_sort(&a, &b, fetch_stack_size(a));
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
		ptr = a;// Initialize ptr to head of the stack.
		value = INT_MIN;// Smallest possible integer.
		top = NULL;// Used to track top number.
		while (ptr)
		{
			if (ptr->num == INT_MIN && ptr->rank == 0)
				ptr->rank = 0;
			if (ptr->num > value && ptr->rank == 0)// Get top number and reset small loop.
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
