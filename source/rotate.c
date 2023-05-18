#include "../include/push_swap.h"

// Rotate the first element to become last.
void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack; // Temp points to first element.
	*stack = (*stack)->next; // Head of stack becomes the 2nd element.
	last = fetch_last_stack(*stack); // Last will point to the last element in the stack.
	temp->next = NULL; // Detach the 1st element from the list.
	// Temp is now a standalone node holding the (now previous) 1st element of the list.
	last->next = temp; // Makes the 1st node the last.
}
// Shift up all elements of stack A by 1.
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
// Shift up all elements of stack B by 1.
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}
// 'ra' and 'rb' at the same time.
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
