#include "../include/push_swap.h"

// Push the top element of a stack to another.
void	push(t_stack **ping, t_stack **pong)
{
	t_stack	*temp;

	if (*ping == NULL)
		return ;
	temp = (*ping)->next;
	(*ping)->next = *pong;
	*pong = *ping;
	*ping = temp;
}

// Take the first element at the top of B and put it at the top of A.
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1,"pa\n",3);
}

// Take the first element at the top of A and put it at the top of B.
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1,"pb\n",3);
}
