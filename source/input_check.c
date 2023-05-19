/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:54:22 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/15 14:54:23 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
Cannot contain duplicate numbers (the following is not allowed)
0 == 00 | 1 == 01 | -1 == -01 | 
*/
// Checks input for incorrect values (accepted values are unique positive or negative numbers).
void	check_input(char *argv[])
{
	int			i;
	int			zeros;
	long int	num;

	i = 1;
	zeros = 0;
	while (argv[i])// Loop to check for not numbers.
	{
		num = ft_atoi(argv[i]);
		if (check_number(argv[i]) == false)// If return is false -> argv[i] wasn't a number.
			error(NULL, NULL);
		if (num > INT_MAX || num < INT_MIN)// Make sure argv[i] isn't bigger than MAX_INT and smaller than INT_MIN.
			error(NULL, NULL);
		if (check_repeat(argv,num,i) == false)// Make sure 01 and 1 aren't there.
			error(NULL, NULL);
		zeros += find_zeros(argv[i]);// Func will return the ammount of single 0's found.
		i++;
	}
	if (check_duplicates(argv) == true || zeros > 1)// Checks for duplicates.
		error(NULL, NULL);
}
// Checks if input contains only a number.
bool	check_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0') // Skips positive and negative and check if number follows sign.
		i++;
	while (argv[i])// Loop to make sure argv[i] contains only integers.
	{
		if ('0' <= argv[i] && argv[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}
// Check values for duplicate types of zeros. (0, 00, -0).
int	find_zeros(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '+' || argv[i] == '-')// Fast forward any signs.
		i++;
	while (argv[i] && argv[i] == '0')// Count until the end of the number.
		i++;
	if (argv[i] != '\0')// If it did reach the end then success.
		return (0);
	return (1);// The number didn't end in 0.
}
// Verifies the input for duplicate values.
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
			if (j != i && dupstring_compare(argv[i],argv[j]) == 0) // Skip if they're the same char.
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
// Compares two strings of digits to check if they are the same or not.
int	dupstring_compare(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// +1 == 1 but -1 != 1.
	if (str1[i] == '+')// Enter if str1 starts with '+'.
	{
		if (str2[j] != '+')// i++ if string2 starts with a '+'.
		i++;
	}
	else// Else '-' or nothing
	{
		if (str2[j] == '+')
		i++;
	}
	while (str1[i] && str2[j] && str1[i] == str2[j])// Incriment whilst both strings are the same and end.
	{
		i++;
		j++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[j]);// Return 0 if the strings match.
}
