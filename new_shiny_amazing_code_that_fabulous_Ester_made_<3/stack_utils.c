#include "push_swap.h"

t_stack *parse_stack(char **av, int ac)
{
    int     i;
    t_stack *stack;
    stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
    if (stack == NULL)
        return (NULL);
    i = 1;
    while (i < ac)
    {
        if (i == 1)
			stack->val = ft_atoi(av[i]);
		else
			stack_add_back(&stack, ft_atoi(av[i]), 0);
        i++;
    }
    return (stack);
}

int is_sorted(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> index < stack -> next -> index)
			stack = stack -> next;
		else
			{
				ft_printf("Stack is nicht sorted!\n");
				return (0);
			}
	}
	ft_printf("Stack is sorted!\n");
	return (1);
}

void index_stack(t_stack *stack, int ac)
{
    int i;
    int swap;
    t_stack *head;

    i = 0;
    head = stack;
    swap = INT_MAX;
    while (i < ac)
    {
        while (stack != NULL)
        {
            if (stack->val == swap && stack->index == 0)
                stack->index = i;
            stack = stack->next;
        }
        stack = head;
        swap = INT_MAX;
        while (stack != NULL)
        {
            if (stack->index == 0 && swap > stack->val)
                swap = stack->val;
            stack = stack->next;
        }
        stack = head;
        i++;
    }
	stack =	head;
}

t_stack *stack_last(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void    stack_add_back(t_stack *lst, int content)
{
    t_stack *old;
    t_stack *new;
    new = ft_calloc(sizeof(t_stack), 1);
    if (new == NULL)
        return ;
    new->val = content;
    new->next = NULL;
    if (lst == NULL)
    {
        lst = new;
        return ;
    }
    old = stack_last(lst);
    old->next = new;
    return ;
}
