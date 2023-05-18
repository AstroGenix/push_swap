#include "../include/push_swap.h"
// Push all numbers into stack B except the last 3.
void	push_all(t_stack **a, t_stack **b, int size)
{
	int	pushed;// Track the number of elements pushed.
	int	i;

	pushed = 0;
	i = 0;
	// i < size ensures that the loop runs through all the elements in stack a.
	// pushed < size / 2 ensures that only half of the elements are pushed to stack b.
	while (i < size && pushed < size / 2)
	{
		// Push if element is of low rank else rotate
		if((*a)->rank <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	// Double check to make sure only 3 elements remaign.
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}
// Shifts the stack so that the lowest value is at the top.
void	shift_order(t_stack **a)
{
	int	low_position;
	int	stack_size;

	stack_size = fetch_stack_size(*a);
	low_position = low_rank_pos(a);
	if (low_position > stack_size / 2)// stack [ here |     ]
	{
		while (low_position < stack_size)
		{
			rra(a);
			low_position++;
		}
	}
	else// stack [     | here ] 
	{
		while (low_position > 0)
		{
			ra(a);
			low_position--;
		}
	}
}
// This function doesn't belong here and should be in input_check.c but due to 5 limit function it is here.
// Make sure 01 and 1 are not the same.
bool	check_repeat(char **argv, int number, int skip)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == number && i != skip)
			return (false);
		i++;
	}
	return (true);
}
