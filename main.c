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

/*
Create special cases for:
• When there is a low ammount of numbers;
Test for github
*/

#include "includes/push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	i = 0;
	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	stack_a = NULL;
	stack_b = NULL;
	list_init(stack_a, argc, argv);
	printf("Stack A\t|\tStack B\n");
	while (argv[i])
    {
		printf("%s\t|\t%s\n", argv[i]);
		i++;
    }
	free(stack_a);
	free(stack_b);

	return (1);
}

static void	list_init(t_list **stack_a, int argc, char *argv[])
{
	t_list	*new;
	int		i;

	i = 0;
	while (argv[i])
	{

	}
}

// LIBFT LIBRARIES

t_list addnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
