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

// input checks
bool	check_input(char *argv[]);
bool	check_number(char *argv);
int		find_zeros(char *argv);
bool	check_duplicates(char *argv[]);
int		dupstring_compare(const char *str1, const char *str2);

// stack manipulation
void	swap(t_list *stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list **ping, t_list **pong);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// sorts
void	three_sort(t_list **stack);
void	four_sort(t_list **stack_a, t_list **stack_b, int size);

// stack creation
t_list	*insert_values(int argc, char *argv[]);
t_list	*stack_add_new(int num);
void	stack_add_bottom(t_list **stack, t_list *new);
t_list	*get_last_stack(t_list *stack);
t_list	*get_penultimate_stack(t_list *stack);

// Number simplification
void	rank_values(t_list *stack_a, int stack_size);

// err handling
void	error(t_list **stack_a, t_list **stack_b);

// util
int		get_stack_size(t_list *stack);
void	free_stack(t_list **stack);
bool	is_sorted(t_list *stack);
void	which_sort(t_list **stack_a, t_list **stack_b, int s_size);
int		top_rank(t_list *stack);
int		min_rank(t_list *stack);

#endif