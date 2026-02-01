/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:30:25 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 12:40:17 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}

static void	rev_rotate(t_stack **s)
{
	t_stack	*prev;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
