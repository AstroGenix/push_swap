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
	//Sort size
	if (argc == 4 || argc == 5)
		printf("Sort 3 or 4 values\n");
	else if (5 < argc && argc < 8)
		printf("Sort between 5 - 6 values\n");
	else if (7 < argc && argc < 103)
		printf("Sort between 7 - 101 values\n");
	else
		printf("Sort more than 102 values\n");
	//Free both stacks

	return (0);
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
	t_list	*x;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	x = get_last_stack(*stack);
	x->next = new;
}

// Retrieve last element of the stack
t_list	*get_last_stack(t_list *stack)
{
	while (stack && stack->next != NULL)
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

//Stack value insert
//Stack free function

/*source/input_check - start*/
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
/*source/input_check - end*/