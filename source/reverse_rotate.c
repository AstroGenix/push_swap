/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:31 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:32 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Rotate the last element to become first.
void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*penult;

	last = fetch_last_stack(*stack); // Get last element of the list.
	penult = fetch_penultimate_stack(*stack); // Get the penultimate element of the list.
	temp = *stack; // Temp points to the first element of the list.
	*stack = last; // New head of the stack is now the last element.
	(*stack)->next = temp; // Attach the head (last element) to the previous head.
	penult->next = NULL; // Detach the penultimate element making it the last.
}

// Shift down all elements of stack A by 1.
void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1,"rra\n",4);
}

// Shift down all elements of stack B by 1.
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1,"rrb\n",4);
}

// 'rra' and 'rrb' at the same time.
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1,"rrr\n",4);
}
