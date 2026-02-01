/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:19:59 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 14:08:44 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*s_new(int v)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = v;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *n)
{
	t_stack	*tmp;

	if (!stack || !n)
		return ;
	if (!*stack)
	{
		*stack = n;
		return ;
	}
	tmp = *stack;
	if (!tmp)
	{
		free_stack(stack);
		free_stack(&n);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
}

int	has_duplicate(t_stack *stack, int v)
{
	while (stack)
	{
		if (stack->value == v)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
