/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:50:27 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/13 14:50:29 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Check if the arguments are allowed.
bool	args_check(int argc, char *argv[])
{
	char	*str;

	if (2 > argc)
		exit (0);
	else if (argc > 2) // Either no arguments or to many arguments.
		return (false);
	else if (!*argv[1]) // If input is empty.
		return (false);
	else // If input only contains spaces.
	{
		str = argv[1];
		while(str)
		{
			if (*str != ' ')
				break;
			str++;
		}
		if (*str == '\0')
			return (false);
	}
	return (true);
}
