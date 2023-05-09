#include "../include/push_swap.h"

// Assign a target position in stack A to each element of stack A.
void	target_position(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		t_position;

	temp_b = *b; // Point to the head of stack B.
	fetch_position(a);
	fetch_position(b);
	t_position = 0; // Variable used to attribute the desired position for an element in the stack.
	while(temp_b)
	{
		t_position = fetch_target(a,temp_b->rank,INT_MAX,t_position);
		temp_b->target_pos = t_position;
		temp_b = temp_b->next;
	}
}

// Assign a potisition to each element of the stack from top to bottom.
void	fetch_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack; // temp will point to the head of the stack.
	i = 0;
	// Loop to get through the stack.
	while (temp)
	{
		temp->pos = i; // Assign i as the position.
		temp = temp->next;
		i++;
	}
}

// Picks the best target position in stack A for the given index of an element in stack B.
int		fetch_target(t_stack **a, int b_rank, int t_rank, int t_position)
{
	t_stack	*temp_a;

	temp_a = *a; // Pointer to the head of the stack A.
	// Loop to find the max rank.
	while (temp_a)
	{
		// Is stack A rank bigger than stack B rank && it's smaller than the max rank?
		if (temp_a->rank > b_rank && temp_a->rank < t_rank)
		{
			t_rank = temp_a->rank;
			t_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	// 
	if (t_rank != INT_MAX)
		return (t_position);
	temp_a = *a;
	// Loop to find the lowest rank.
	while (temp_a)
	{
		if (temp_a->rank < t_rank)
		{
			t_rank = temp_a->rank;
			t_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	// Return the lowest rank found.
	return (t_position);
}

// Retrieve the position of the element with the lowest rank.
int	low_rank_pos(t_stack **stack)
{
	t_stack *temp;
	int		low_rank;
	int		low_position;

	temp = *stack;
	low_rank = INT_MAX;
	fetch_position(stack);
	low_position = temp->pos;
    // Loop and save the position of the lowest rank.
	while (temp)
	{
		if (temp->rank < low_rank)
		{
			low_rank = temp->rank;
			low_position = temp->pos;
		}
		temp = temp->next;
	}
	return (low_position);
}