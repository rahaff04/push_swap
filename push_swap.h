#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*s_new(int v);
void	add_back(t_stack **stack, t_stack *n);
int		has_duplicate(t_stack *stack, int v);
void	free_stack(t_stack **stack);
int		write_error(void);
int		init_stack(int ac, char **av, t_stack **a);
int		parse_split(char *av, t_stack **a);
int		parse(int ac, char **av, t_stack **a);
int		get_size(t_stack *a);
int		find_min(t_stack *a);
int		find_max(t_stack *a);
int		get_index(t_stack *a, int v);
void	sa(t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sb(t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);

#endif