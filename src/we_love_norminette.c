/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   we_love_norminette.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:14:42 by jfoltan           #+#    #+#             */
/*   Updated: 2023/08/04 17:11:10 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_util(t_stack *stack, int i, int swap)
{
	while (stack != NULL)
	{
		if (stack->val == swap && stack->index == 0)
			stack->index = i;
		stack = stack->next;
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(2);
}

int	preliminary_check(char **args)
{
	int		i;
	int		j;
	long	swap;

	i = 0;
	j = 0;
	swap = 0;
	while (args[++i])
	{
		while (args[i][j])
		{
			if (args[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(args[i][j]))
				error();
			if (ft_isalpha(args[i][j]))
				error();
			j++;
		}
		swap = ft_atol(args[i]);
		if (swap > INT_MAX || swap < INT_MIN)
			error();
		j = 0;
	}
	return (1);
}
