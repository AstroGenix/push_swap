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

//
void	shift_order(t_stack **a)
{
	int	low_position;
	int	stack_size;

	stack_size = fetch_stack_size(*a);
	low_position = low_rank_pos(a);
	if (low_position > stack_size / 2)
	{
		while (low_position < stack_size)
		{
			rra(a);
			low_position++;
		}
	}
	else
	{
		while (low_position > 0)
		{
			ra(a);
			low_position--;
		}
	}
}
//
int	low_rank_pos(t_stack **stack)
{
	t_stack *temp;
	int		low_rank;
	int		low_position;

	temp = *stack;
	low_rank = INT_MAX;
	fetch_position(stack);
	low_position = temp->pos;
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

// Calculates the cost of moving each element of stack B into the correct position in stack A. - TO COMMENT
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *a;
	temp_b = *b;
	size_a = fetch_stack_size(temp_a);
	size_b = fetch_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

// Finds the element in stack B with the cheapest cost to move to stack A. -TO COMMENT
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		if(abs_num(temp->cost_a) + abs_num(temp->cost_b) < abs_num(cheapest))
		{
			cheapest = abs_num(temp->cost_a) + abs_num(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	move(a,b,cost_a,cost_b);
}

// Select the best move to get stack B element to the correct position in stack A. - TO COMMENT
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a,b);
}
//
void	rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a,b);
	}
}
//
void	r_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a,b);
	}
}
//
void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}
//
void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

// Assign a target position in stack A to each element of stack A. - TO COMMENT
void	target_position(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		t_position;

	temp_b = *b;
	fetch_position(a);
	fetch_position(b);
	t_position = 0;
	while(temp_b)
	{
		t_position = fetch_target(a,temp_b->rank,INT_MAX,t_position);
		temp_b->target_pos = t_position;
		temp_b = temp_b->next;
	}
}

// Assign a potisition to each element of the stack from top to bottom. - TO COMMENT
void	fetch_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

// Picks the best target position in stack A for the given index of an element in stack B. - TO COMMENT
int		fetch_target(t_stack **a, int b_rank, int t_rank, int t_position)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->rank > b_rank && temp_a->rank < t_rank)
		{
			t_rank = temp_a->rank;
			t_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (t_rank != INT_MAX)
		return (t_position);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->rank < t_rank)
		{
			t_rank = temp_a->rank;
			t_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (t_position);
}

/*
* Stack manipulation - start
*/
// Push all numbers into stack B except the last 3.
void	push_all(t_stack **a, t_stack **b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (i < size && pushed < size / 2 && size > 6)
	{
		if((*a)->rank <= size / 2)
		{
			pb(a,b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a,b);
		pushed++;
	}
}

/*
* Stack manipulation - end
*/
