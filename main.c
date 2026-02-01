/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:18:15 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 12:36:30 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = get_size(*a);
	if (!is_sorted(*a))
	{
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
