/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:56:59 by jfoltan           #+#    #+#             */
/*   Updated: 2023/08/04 14:05:28 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list *a_stack)
{
	if (rotate(a_stack))
	{
		ft_putendl_fd("ra", 1);
		return (1);
	}
	return (0);
}

int	rb(t_list a_stack)
{
	if (rotate(&a_stack))
	{
		ft_putendl_fd("rb", 1);
		return (1);
	}
	return (0);
}

int	rra(t_list *a_stack)
{
	if (rev_rotate(a_stack))
	{
		ft_putendl_fd("rra", 1);
		return (1);
	}
	return (0);
}

int	rrb(t_list *b_stack)
{
	if (rev_rotate(b_stack))
	{
		ft_putendl_fd("rrb", 1);
		return (1);
	}
	return (0);
}

int	rrr(t_list *a_stack, t_list *b_stack)
{
	if (rev_rotate(a_stack) && rev_rotate(b_stack))
	{
		ft_putendl_fd("rrr", 1);
		return (1);
	}
	return (0);
}
