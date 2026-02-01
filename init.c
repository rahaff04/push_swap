/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 09:26:21 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 12:39:32 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		indx;

	i = a;
	while (i)
	{
		indx = 0;
		j = a;
		while (j)
		{
			if (i->value > j->value)
				indx++;
			j = j->next;
		}
		i->index = indx;
		i = i->next;
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
