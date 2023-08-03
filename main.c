/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:23:00 by emollebr          #+#    #+#             */
/*   Updated: 2023/08/03 22:39:45 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->index < stack->next->index)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	argcheck(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if_args(args, i, j, 1);
			j++;
		}
		j = 0;
		while (j < i)
		{
			if_args(args, i, j, 2);
			j++;
		}
		i++;
	}
	return (1);
}

void	sort_stack(t_stack **a_stack, t_stack **b_stack, int size)
{
	index_stack(*a_stack, size + 1);
	if (is_sorted(*a_stack))
		return ;
	if (size == 3)
		sort_3(a_stack);
	if (size == 4)
		sort_4(a_stack, b_stack);
	if (size == 5)
		sort_5(a_stack, b_stack);
	if (size > 5)
		a_stack = radix_sort(a_stack, b_stack);
}

char	**args_handling(char **av, int ac)
{
	char	**args;

	args = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		argcheck(args);
	}
	else
	{
		args = av_to_arg(av, args);
		argcheck(args);
	}
	return (args);
}
void    print_stack (t_stack *stack)
{
    int i;
    int size;
    if (!stack)
        return ;
    size =  stack_size(stack);
    i = 1;
    while (i < size)
    {
        printf("val: %d\n", stack->val);
        stack = stack -> next;
        i++;
    }
    printf("val: %d\n", stack->val);
    printf("\n");
}
int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	**args;
	int		size;


	args = args_handling(av, ac);
	size = get_size(args, -1);
	if (size == 0)
		exit (1);
	if (size == 2)
	{
		if (ft_atoi(args[0]) > ft_atoi(args[1]))
			write(1, "sa\n", 1);
		exit (1);
	}
	//b_stack = ft_calloc(1, 8);
	a_stack = parse_stack(args, size);
	b_stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	sort_stack(&a_stack, &b_stack, size);
	free_arr(args);
	free_tab(a_stack);
	free_tab(b_stack);
	return (0);
}
