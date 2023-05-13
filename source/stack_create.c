#include "../include/push_swap.h"

// Insert the values into the stack.
t_stack	*insert_values(int argc, char *argv[], int flag)
{
	t_stack		*a;
	long int	num;
	int			i;

	a = NULL;
	num = 0;
	if (flag == 1)
		i = 1;
	else
		i = 0;
	//Loop
	while (i < argc)
	{
		//Transform char into int
		num = ft_atoi(argv[i]);
		//Check for number overflow
		if ( INT_MIN > num || num > INT_MAX)
			error(&a, NULL);
		//Create of the stack
		if (i == flag) //Create head for the stack
			a = stack_add_new((int)num);
		else //Values after head get added to bottom
			stack_add_bottom(&a,stack_add_new((int)num));
		i++;
	}
	return (a);
}

// Add a new value to the stack and initialize all of it's properties.
t_stack	*stack_add_new(int num)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->num = num;
	new->rank = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

// Add a value to the bottom of the stack
void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = fetch_last_stack(*stack);
	last->next = new;
}
