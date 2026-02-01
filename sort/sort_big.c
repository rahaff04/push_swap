/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:17:26 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 10:17:28 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_max_index(t_stack *a)
{
	int	max_indx;

	max_indx = -1;
	while (a)
	{
		if (a->index > max_indx)
			max_indx = a->index;
		a = a->next;
	}
	return (max_indx);
}

static int	bits_count(t_stack *a)
{
	int	max;
	int	bits;

	max = find_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	size;
	int	bits;

	size = get_size(*a);
	bits = bits_count(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (get_size(*b) > 0)
			pa(a, b);
		i++;
	}
}

/*
3 1 2

0 1
1 2 
2 3

a -> 2 0 1
b -> --

max-index = 2
bits :

bits = 0 -> 2 >> 0 = 2 != 0
bits = 1 -> 2 >> 1 = 1 != 0
bits = 2 -> 2 >> 2 = 0 == 0 stop -> bits = 2

i = 0
j = 0

size = 3

2 >> 0 & 1 = 0 pb

a : 0 1
b: 2

0 >> 0 & 1 = 0 pb
a: 1
b: 0 2

1 >> 0 & 1 = 1 ra
a: 1
b: 0 2

pa
a : 0 1
b : 2
pa
a : 2 0 1
b : --
j is over first iteration

j = 0

2 >> 1 & 1 = 1 ra
a : 0 1 2
b : --

0 >> 1 & 1 = 0 pb
a : 1 2
b : 0

1 >> 1 & 1 = 0 pb
a: 2
b : 1 0

pa
a 1 2
b 0
pa
a: 0 1 2  -> as index
b:-- 

0  1
1   2
2   3

*/
