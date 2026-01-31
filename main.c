#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = get_size(*a);
	if (size <= 5)
	{
		if (size == 2)
			sort_2(a);
		else if (size == 3)
			sort_3(a);
		else if (size == 4)
			sort_4(a, b);
		else if (size == 5)
			sort_5(a, b);
	}
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!init_stack(ac, av, &a))
		return (1);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
