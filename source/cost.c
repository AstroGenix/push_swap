/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:09 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:12 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// Calculates the cost of moving each element of stack B into the correct position in stack A.
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
	// cost_b - the cost of moving the element from its current position in stack B to the top of stack B.
	// cost_a - the cost of moving the element from wherever it is to its target position in stack A.
	while (temp_b)
	{
        // Becomes the cost to get the target to the top of stack B.
		temp_b->cost_b = temp_b->pos;
		// Depending where the element is cost can be negative.
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1; // stack [  | x ] latter half.
         // Cost to move element in stack B to its target position in stack A.
		temp_b->cost_a = temp_b->target_pos;
        // If target position is closer to the bottom of stack A, the cost is negative.
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}
// Finds the element in stack B with the cheapest cost to move to stack A.
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	// Loop through each element and at the end only the cheapest move is sent.
	while (temp)
	{
		// If the cost of moving the element from stack B to stack A is less than the current cheapest cost,
		// update the cheapest cost and store the costs for this move.
		if(abs_num(temp->cost_a) + abs_num(temp->cost_b) < abs_num(cheapest))
		{
			cheapest = abs_num(temp->cost_a) + abs_num(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	move(a, b, cost_a, cost_b);
}
