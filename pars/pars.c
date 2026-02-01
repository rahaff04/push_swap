/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:18:52 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 14:08:05 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	error_free(t_stack **a)
{
	free_stack(a);
	write_error();
	return (0);
}

int	parse(int ac, char **av, t_stack **a)
{
	long	n;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_is_number(av[i]))
			error_free(a);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_free(a);
		if (has_duplicate(*a, (int)n))
			error_free(a);
		add_back(a, s_new((int)n));
		i++;
	}
	return (1);
}
