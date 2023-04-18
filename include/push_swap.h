/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:19:57 by dberehov          #+#    #+#             */
/*   Updated: 2023/03/14 11:20:02 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// C Libraries
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
// 42 Libraries
# include "libft/libft.h"
# include "ft_printf/includes/ft_printf.h"

// Stack Structure
typedef struct s_list
{
	int				num;
	int				rank;
	struct s_list	*next;	
}	t_list;

// input_check.c
bool	check_input(char *argv[]);
bool	check_number(char *argv);
int		find_zeros(char *argv);
bool	check_duplicates(char *argv[]);
int		dupstring_compare(const char *str1, const char *str2);

// stack creation
t_list	*insert_values(int argc, char *argv[]);
t_list	*stack_add_new(int num);
void	stack_add_bottom(t_list **stack, t_list *new);
t_list	*get_last_stack(t_list *stack);

// Number simplification
void	rank_values(t_list *stack_a, int stack_size);

// err handling
void	error(t_list **stack_a, t_list **stack_b);

// util
int		get_stack_size(t_list *stack);
void	free_stack(t_list **stack);

#endif