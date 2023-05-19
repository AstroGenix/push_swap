#include "../include/push_swap.h"

void	validate_more(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		rra(a);
	else if (line[2] == 'b')
		rrb(b);
	else if (line[2] == 'r')
		rrr(a, b);
}

char	*validate(t_stack **a,t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		validate_more(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b);
	else
		error(NULL,NULL);
	return (get_next_line(0));
}

void	checker_input(t_stack **a, t_stack **b, char *line)
{
	while (line && *line != '\n')
		line = validate(a, b, line);
	if (!is_sorted(*a))
		write(1, "KO\n", 3);
	else if (*b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	
	check_input(argv);
	b = NULL;
	a = insert_values(argc, argv);
	line = get_next_line(0);
	if (!line && !is_sorted(a))
		write(1, "KO\n", 3);
	else if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		checker_input(&a, &b, line);
	free_stack(&a);
	free_stack(&b);
	return (0);
}