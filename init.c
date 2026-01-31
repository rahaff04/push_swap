#include "push_swap.h"

static t_stack	*get_min_unindexed(t_stack *a)
{
	t_stack	*min;
	int		value;

	min = NULL;
	value = INT_MAX;
	while (a)
	{
		if (a->index == -1 && a->value < value)
		{
			value = a->value;
			min = a;
		}
		a = a->next;
	}
	return (min);
}

static void	set_index(t_stack *a)
{
	int		i;
	int		size;
	t_stack	*tmp;
	t_stack	*min;

	size = get_size(a);
	i = 0;
	tmp = a;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
	while (i < size)
	{
		min = get_min_unindexed(a);
		min->index = i;
		i++;
	}
}

static int	parse_args(int ac, char **av, t_stack **a)
{
	if (ac < 2)
		return (1);
	if (ac == 2)
	{
		if (!parse_split(av[1], a))
			return (0);
	}
	else
	{
		if (!parse(ac, av, a))
			return (0);
	}
	return (1);
}

int	init_stack(int ac, char **av, t_stack **a)
{
	if (!parse_args(ac, av, a))
		return (0);
	if (get_size(*a) > 5)
		set_index(*a);
	return (1);
}
