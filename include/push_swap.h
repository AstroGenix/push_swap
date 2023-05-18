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
# include <string.h>

// Stack Structure
typedef struct s_stack
{
	int				num; // The user input is stored here.
	int				rank; // A rank attributed to the number to make it easier to sort.
	int				pos; // The current position of the element.
	int				target_pos; // Where it should be in stack A.
	int				cost_a; // The cost to get it to stack A.
	int				cost_b; // The cost to get it to the top o stack B.
	struct s_stack	*next;	
}	t_stack;

// Argument check                                  Status
bool		args_check(int argc, char *argv[]); //   ✔

// Input checks                                                        Status
void		check_input(char *argv[], int flag); //                      ✔
bool		check_number(char *argv); //                                 ✔
int			find_zeros(char *argv); //                                   ✔
bool		check_duplicates(char *argv[]); //                           ✔
int			dupstring_compare(const char *str1, const char *str2); //    ✔
bool    	check_repeat(char **argv, int number, int skip); //          ✔

// Stack manipulation                                          Status
void		swap(t_stack *stack); //                             ✔
void		rotate(t_stack **stack); //                          ✔
void		reverse_rotate(t_stack **stack); //                  ✔
void		push(t_stack **ping, t_stack **pong); //             ✔
void		push_all(t_stack **a, t_stack **b, int size); //     ✔
void		shift_order(t_stack **a); //                         ✔

// Stack operations                                Status
void		sa(t_stack **a); //                      ✔
void		sb(t_stack **b); //                      ✔
void		ss(t_stack **a, t_stack **b); //         ✔
void		pa(t_stack **a, t_stack **b); //         ✔
void		pb(t_stack **a, t_stack **b); //         ✔
void		ra(t_stack **a); //                      ✔
void		rb(t_stack **a); //                      ✔
void		rr(t_stack **a, t_stack **b); //         ✔
void		rra(t_stack **a); //                     ✔
void		rrb(t_stack **b); //                     ✔
void		rrr(t_stack **a, t_stack **b); //        ✔

// Sorts                                                      Status
void		three_sort(t_stack **a);//                          ✔
void		four_sort(t_stack **a, t_stack **b);//              ✔
void		big_sort(t_stack **a, t_stack **b, int size);//     ✔

// Sort utils                                                                           Status
void		target_position(t_stack **a, t_stack **b);//                                  ✔
void		fetch_position(t_stack **stack);//                                            ✔
int			fetch_target(t_stack **a, int b_rank, int t_rank, int t_position);//          ✔
void		get_cost(t_stack **a, t_stack **b);//                                         ✔
void		do_cheapest_move(t_stack **a, t_stack **b);//                                 ✔
void		move(t_stack **a, t_stack **b, int cost_a, int cost_b);//                     ✔
int			low_rank_pos(t_stack **stack);//                                              ✔
void		rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);//                ✔
void		r_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);//                 ✔
void		rotate_a(t_stack **a, int *cost);//                                           ✔
void		rotate_b(t_stack **b, int *cost);//                                           ✔

// Stack creation                                                    Status
t_stack		*insert_values(int argc, char *argv[], int flag); //       ✔
t_stack		*stack_add_new(int num); //                                ✔
void		stack_add_bottom(t_stack **stack, t_stack *new); //        ✔
t_stack		*fetch_last_stack(t_stack *stack); //                      ✔
t_stack		*fetch_penultimate_stack(t_stack *stack); //               ✔

// Number simplification                                Status
void		rank_values(t_stack *a, int stack_size); //   ✔

// Error handling                                      Status
void		error(t_stack **a, t_stack **b); //           ✔

// Utilitary                                                       Status
int			fetch_stack_size(t_stack *stack); //                     ✔
void		free_stack(t_stack **stack); //                          ✔
bool		is_sorted(t_stack *stack); //                            ✔
void		which_sort(t_stack **a, t_stack **b, int s_size); //     ✔
int			top_rank(t_stack *stack); //                             ✔
int			abs_num(int num); //                                     ✔
long int		ft_atoi(const char *nptr); //                        ✔
char		**ft_split(char const *s, char c);//                     ✔
#endif