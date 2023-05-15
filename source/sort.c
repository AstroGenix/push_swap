/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:44 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:46 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
* three sort:
	[1] [3] [2] -> rra & sa
	[2] [3] [1] -> rra
	[2] [1] [3] -> sa
	[3] [1] [2] -> ra
	[3] [2] [1] -> ra  & sa

* four sort: (Not easy to translate into code)
	[1] [2] [4] [3] -> rra & rra & sa & ra & ra  | [2] [1] [3] [4] -> sa
	[1] [3] [2] [4] -> sa  & rra & sa & ra & ra  | [2] [1] [4] [3] -> pb  & pb  & ss & pa & pa
	[1] [3] [4] [2] -> rra & sa                  | [2] [3] [1] [4] -> rra & rra & sa & ra
	[1] [4] [2] [3] -> sa  & ra                  | [2] [3] [4] [1] -> rra
	[1] [4] [3] [2] -> sa  & ra  & ra & sa & rra | [2] [4] [1] [3] -> sa  & ra  & sa
												 | [2] [4] [3] [1] -> sa  & rra & sa & ra
	- - - - - - - - - - - - - - - - - - - - - - -|- - - - - - - - - - - - - - - - - - - - 
	[3] [1] [2] [4] -> rra & sa  & ra & ra       | [4] [1] [2] [3] -> ra 
	[3] [1] [4] [2] -> ra  & sa  & ra            | [4] [1] [3] [2] -> ra  & ra  & sa  & rra
	[3] [2] [1] [4] -> sa  & ra  & sa & rra & sa | [4] [2] [1] [3] -> ra  & sa
	[3] [2] [4] [1] -> sa  & rra                 | [4] [2] [3] [1] -> rra & sa  & ra
	[3] [4] [2] [1] -> rra & rra & sa            | [4] [3] [1] [2] -> sa  & rra & rra
	[3] [4] [1] [2] -> rra & rra                 | [4] [3] [2] [1] -> sa  & rra & rra & sa
*/

// Choose based on ammount of values which sort to use.
void	which_sort(t_stack **a, t_stack **b, int s_size)
{
	if (s_size == 2)
		sa(a);
	else if (s_size == 3)
		three_sort(a);
	else if (s_size == 4)
		four_sort(a,b);
	else
		big_sort(a,b,s_size);
}

// Sort a size 3 stack using the rank values.
void	three_sort(t_stack **stack)
{
	int	top;

	top = top_rank(*stack);
	if ((*stack)->rank == top) // [3] [x] [x]
		ra(stack);
	else if ((*stack)->next->rank == top) // [x] [3] [x]
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank) // [2] [1] [3] - 3 cannot be first due to first if.
		sa(stack);
}

// Sort a size 4 stack using rank values.
void	four_sort(t_stack **a, t_stack **b)
{
	if ((*a)->rank == 2 && (*a)->next->rank == 1 && (*a)->next->next->rank == 3)
		sa(a); // Specific case 1 [2] [1] [3] [4]
	else if ((*a)->rank == 2 && (*a)->next->rank == 3 && (*a)->next->next->rank == 4)
		rra(a); // Specific case 1 [2] [3] [4] [1]
	else if ((*a)->next->next->next->rank == 4) // [x] [x] [x] [4]
		rra(a);
	else if ((*a)->next->rank == 4) // [x] [4] [x] [x]
		ra(a);
	else if ((*a)->next->next->rank == 4) // [x] [x] [4] [x]
	{
		rra(a);
		rra(a);
	}
	if (is_sorted((*a)) == true)
	    return ;
	pb(a,b);
	three_sort(a); // Basically send the biggest rank to stack B and the other through the three_sort.
	pa(a,b);
	ra(a);
}

// Push all numbers to stack B and calculate the best moves to sort. - TO COMMENT
void	big_sort(t_stack **a, t_stack **b, int size)
{
	push_all(a, b, size); // Push all the small ranks first into stack B leaving 3 in stack A.
	three_sort(a); // Sort the remaining numbers.
	while(*b)
	{
		target_position(a,b);
		get_cost(a,b);
		do_cheapest_move(a,b);
	}
	if(!is_sorted(*a))
		shift_order(a); // Shift the stack back into order.
	
}
