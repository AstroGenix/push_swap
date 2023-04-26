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
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;

	if (argc < 2) // If /a.out is the only input exit.
		return (0);
	if (check_input(argv) == false) // Check input for abnormalities or duplicates (unique numbers only).
		error(NULL, NULL);
	stack_b = NULL;
	stack_a = insert_values(argc, argv);
	stack_size = get_stack_size(stack_a);
	rank_values(stack_a, stack_size + 1);
	if (!is_sorted(stack_a))
		which_sort(&stack_a,&stack_b,stack_size);
	// Free both stacks
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

// Find the max rank in the stack.
int	top_rank(t_list *stack)
{
	int	rank;

	rank = stack->rank;
	// Loop saves biggest rank found
	while (stack)
	{
		if (stack->rank > rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

// Find the minimum rank in the stack.
int	min_rank(t_list *stack)
{
	int	rank;

	rank = stack->rank;
	// Loop saves biggest rank found
	while (stack)
	{
		if (stack->rank < rank)
			rank = stack->rank;
		stack = stack->next;
	}
	return (rank);
}

/*
* Sorts - start
* three sort:
	[1] [3] [2] -> rra & sa
	[2] [3] [1] -> rra
	[2] [1] [3] -> sa
	[3] [1] [2] -> ra
	[3] [2] [1] -> ra  & sa

* four sort:
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
// Sort a size 3 stack using the rank values.
void	three_sort(t_list **stack)
{
	int	top;

	top = top_rank(*stack);
	if ((*stack)->rank == top) // [3] [x] [x]
		ra(stack);
	else if ((*stack)->next->rank == top) // [x] [3] [x]
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank) // [2] [1] [3] - 3 cannot be first due to first if
		sa(stack);
}

// Sort a size 4 stack using rank values.
void	four_sort(t_list **stack_a, t_list **stack_b)
{
	int	top;
	int	size;

	top = top_rank(*stack_a); //will be 4
	size = top_rank(*stack_a);
	/*
	Do special cases first (one command):
		[2] [1] [3] [4]
		[2] [3] [4] [1]
		[4] [1] [2] [3]
	Do special case for [2] [1] [4] [3]
		pb  & pb  & ss & pa & pa
	Send [4] to stack B and sort stack A
	*/
	if ((*stack_a)->rank == 4)
        ra(stack_a);
	while (size)
    {
        printf("Num[%d]->%d\n", size, (*stack_a)->num);
        (*stack_a) = (*stack_a)->next;
        size--;
    }
}
/*
* Sorts - end
*/

/*
* Stack manipulation - start
*/
// Push the top element of a stack to another.
void	push(t_list **ping, t_list **pong)
{
	t_list	*temp;

	if (*ping == NULL)
		return ;
	temp = (*ping)->next;
	(*ping)->next = *pong;
	*pong = *ping;
	*ping = temp;
}

// Take the first element at the top of B and put it at the top of A.
void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1,"pa\n",3);
}

// Take the first element at the top of A and put it at the top of B.
void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1,"pb\n",3);
}

// Rotate the last element to become first.
void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;
	t_list	*penult;

	last = get_last_stack(*stack); // Get last element of the list.
	penult = get_penultimate_stack(*stack); // Get the penultimate element of the list.
	temp = *stack; // Temp points to the first element of the list.
	*stack = last; // New head of the stack is now the last element.
	(*stack)->next = temp; // Attach the head (last element) to the previous head.
	penult->next = NULL; // Detach the penultimate element making it the last.
}

// Shift down all elements of stack A by 1.
void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1,"rra\n",4);
}

// Shift down all elements of stack B by 1/
void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1,"rrb\n",4);
}

// 'rra' and 'rrb' at the same time.
void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1,"rrr\n",4);
}

// Rotate the first element to become last.
void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	temp = *stack; // Temp points to first element.
	*stack = (*stack)->next; // Head of stack becomes the 2nd element.
	last = get_last_stack(*stack);
	temp->next = NULL; // Detach the 1st element from the list.
	// Temp is now a standalone node holding the (now previous) 1st element of the list.
	last->next = temp; // Makes the 1st node the last.
}

// Shift up all elements of stack A by 1.
void	ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1,"ra\n",3);
}

// Shift up all elements of stack B by 1.
void	rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1,"rb\n",3);
}

// 'ra' and 'rb' at the same time.
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1,"rr\n",3);
}

// Swap the top 2 elements of the stack.
void	swap(t_list *stack)
{
	int temp;

	// Switch the numbers
	temp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = temp;

	// Switch the ranks
	temp = stack->rank;
	stack->rank = stack->next->rank;
	stack->next->rank = temp;
}
// Swap the first 2 elements at the top of stack a.
void	sa(t_list **stack_a)
{
	swap(*stack_a);
	write(1,"sa\n",3);
}

// Swap the first 2 elements at the top of stack b.
void	sb(t_list **stack_b)
{
	swap(*stack_b);
	write(1,"sb\n",3);
}

// 'sa' and 'sb' at the same time.
void	ss(t_list **stack_a,t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1,"ss\n",3);
}
/*
* Stack manipulation - end
*/

// Choose based on ammount of values which sort to use.
void	which_sort(t_list **stack_a, t_list **stack_b, int s_size)
{
	if (s_size == 2)
		sa(stack_a);
	else if (s_size == 3)
		three_sort(stack_a);
	else if (s_size == 4)
		four_sort(stack_a,stack_b);
	else
		printf("Sort more than 5 values\n");
}

// Checks if stack is sorted from min to max.
bool	is_sorted(t_list *stack)
{
	while(stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	printf("It do be sorted.\n");
	return (true);
}

// Free a stack and set it to null.
void	free_stack(t_list **stack)
{
	t_list	*temp;

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

// Will rank the values in stack A to make it easier to order. (ranked top (stack_size) to bottom (1))
void	rank_values(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*top;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a; // Initialize ptr to head of the stack.
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
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (top != NULL)
			top->rank = stack_size;
	}
}

// Return the amount of values in the stack.
int	get_stack_size(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// Insert the values into the stack.
t_list	*insert_values(int argc, char *argv[])
{
	t_list		*stack_a;
	long int	num;
	int			i;

	stack_a = NULL;
	num = 0;
	i = 1;
	//Loop
	while (i < argc)
	{
		//Transform char into int
		num = ft_atoi(argv[i]);
		//Check for number overflow
		if ( INT_MIN > num || num > INT_MAX)
			error(&stack_a, NULL);
		//Create of the stack
		if (i == 1) //Create head for the stack
			stack_a = stack_add_new((int)num);
		else //Values after head get added to bottom
			stack_add_bottom(&stack_a,stack_add_new((int)num));
		i++;
	}
	return (stack_a);
}

// Add a new value to the stack
t_list	*stack_add_new(int num)
{
	t_list	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

// Add a value to the bottom of the stack
void	stack_add_bottom(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = get_last_stack(*stack);
	last->next = new;
}

// Retrieve last element of the stack
t_list	*get_last_stack(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

// Retrieve the penultimate element of the stack
t_list	*get_penultimate_stack(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

// In case of error free the stacks and output err message.
void	error(t_list **stack_a, t_list **stack_b)
{
	free(stack_a);
	free(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}


/*
* source/input_check - start
*/
// main - checks input for incorrect values (accepted values are unique positive or negative numbers).
bool	check_input(char *argv[])
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (argv[i]) // Loop to check for not numbers.
	{
		if (check_number(argv[i]) == false) // If return is false -> argv[i] wasn't a number.
			return (false);
		zeros += find_zeros(argv[i]);
		i++;
	}
	if (check_duplicates(argv) == true || zeros > 1) // Checks for duplicates.
		return (false);
	return (true);
}

// check_input - Checks if input contains only a number.
bool	check_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0') // Skips positive and negative and check if number follows sign.
		i++;
	while (argv[i])
	{
		if ('0' <= argv[i] && argv[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

//check_input - Check values for duplicate types of zeros. (0, 00, -0).
int	find_zeros(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while (argv[i] == 0 && argv[i] != '\0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

// check_input - verifies the input for duplicate values.
bool	check_duplicates(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	// Big loop to compare i char to j.
	while (argv[i])
	{
		j = 1;
		// Small loop to check for dups
		while (argv[j])
		{
			if (j != i && dupstring_compare(argv[i],argv[j]) == 0) // Don't compare if they're the same char.
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

// check_duplicates - Compares two strings of digits to check if they are the same or not.
int	dupstring_compare(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// +1 == 1 but -1 != 1.
	if (str1[i] == '+') // Enter if str1 starts with '+'.
	{
		if (str2[j] != '+') // i++ if string2 starts with a '+'.
		i++;
	}
	else // Else '-' or nothing
	{
		if (str2[j] == '+')
		i++;
	}
	while (str1[i] && str2[j] && str1[i] == str2[j]) // Incriment whilst both strings are the same and end.
	{
		i++;
		j++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[j]); // Return 0 if the strings match.
}
/*
* source/input_check - end
*/