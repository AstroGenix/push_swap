/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:16 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:17 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// Select the best move to get stack B element to the correct position in stack A.
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	// If both costs are negative, perform a reverse rotation of both stacks until one or both costs become non-negative.
	if (cost_a < 0 && cost_b < 0)
		rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)// If both costs are positive, perform a rotation of both stacks until one or both costs become non-positive.
		r_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);// Perform a rotation of stack A if the cost is non-zero.
	rotate_b(b, &cost_b);// Perform a rotation of stack B if the cost is non-zero.
	pa(a, b);
}
// Rotate both stacks in reverse order until one of the costs becomes positive.
void	rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}
// Rotate both stacks until one of the costs becomes negative.
void	r_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}
// Rotate stack A until cost reaches 0.
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
// Rotate stack B until cost reaches 0.
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
