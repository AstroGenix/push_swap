/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:55:30 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:55:31 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
// Return absolute number |-1| == |1| == 1
int	abs_num(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
// In case of error free the stacks and output error message.
void	error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)// Check if the pointer is NULL or that the pointer isn't pointing to a NULL.
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
// Free a stack and set it to null.
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
// Checks if stack is sorted from min to max.
bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}
// Converts the initial portion of the string pointed to nptr to int.
long int	ft_atoi(const char *nptr)
{
	int				i;
	int				ngtv;
	long long int	result;

	i = 0;
	ngtv = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			ngtv = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i] - '0') + (result * 10);
		i++;
	}
	if ((ngtv * result) > 2147483647 || (ngtv * result) < -2147483648)
		error(NULL, NULL);
	return (result * ngtv);
}

