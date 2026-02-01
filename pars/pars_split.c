/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:19:05 by ralamair          #+#    #+#             */
/*   Updated: 2026/02/01 10:19:06 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static int	check_split(char *num_str, t_stack **a)
{
	long	n;
	t_stack	*node;

	if (!ft_is_number(num_str))
		return (0);
	n = ft_atol(num_str);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	if (has_duplicate(*a, (int)n))
		return (0);
	node = s_new((int)n);
	if (!node)
		return (0);
	add_back(a, node);
	return (1);
}

int	parse_split(char *av, t_stack **a)
{
	char	**num;
	int		i;

	num = ft_split(av, ' ');
	if (!num)
		return (write_error());
	i = 0;
	while (num[i])
	{
		if (!check_split(num[i], a))
		{
			free_split(num);
			return (write_error());
		}
		i++;
	}
	free_split(num);
	return (1);
}
