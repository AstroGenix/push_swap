#include "../include/push_swap.h"

// Swap the top 2 elements of the stack.
void	swap(t_stack *stack)
{
	int temp;

	// Switch the numbers
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;

	// Switch the ranks
	temp = stack->rank;
	stack->rank = stack->next->rank;
	stack->next->rank = temp;
}
// Swap the first 2 elements at the top of stack a.
void	sa(t_stack **a)
{
	swap(*a);
	write(1,"sa\n",3);
}

// Swap the first 2 elements at the top of stack b.
void	sb(t_stack **b)
{
	swap(*b);
	write(1,"sb\n",3);
}

// 'sa' and 'sb' at the same time.
void	ss(t_stack **a,t_stack **b)
{
	swap(*a);
	swap(*b);
	write(1,"ss\n",3);
}