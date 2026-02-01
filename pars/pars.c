/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:18:52 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 10:18:54 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	parse(int ac, char **av, t_stack **a)
{
	long	n;
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_is_number(av[i]))
			return (write_error());
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (write_error());
		if (has_duplicate(*a, (int)n))
			return (write_error());
		add_back(a, s_new((int)n));
		i++;
	}
	return (1);
}
