#include "../include/push_swap.h"

// Find the top/max rank in the stack.
int	top_rank(t_stack *stack)
{
	int	rank;

	rank = stack->rank;
	while (stack) // Loop saves biggest rank found.
	{
		if (stack->rank > rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

// Return the amount of values in the stack.
int	fetch_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// Retrieve last element of the stack
t_stack	*fetch_last_stack(t_stack *stack)
{
	while (stack && stack->next != NULL) // Loop until it reaches the last element.
		stack = stack->next;
	return (stack);
}

// Retrieve the penultimate element of the stack
t_stack	*fetch_penultimate_stack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL) // Loop until it reaches the element prior the last one.
		stack = stack->next;
	return (stack);
}