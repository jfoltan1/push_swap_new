#include "push_swap.h"
#include <limits.h>

t_stack *stack_last(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}

void stack_add_back(t_stack **lst, int content, int index)
{
    t_stack *new;

	new = ft_calloc(1, sizeof(t_stack));
    if (new == NULL)
        return;
    new->val = content;
    new->index = index;
    new->next = NULL;

    if (*lst == NULL)
    {
        *lst = new;
        return;
    }

    t_stack *old = stack_last(*lst);
    old->next = new;
}

void	print_stack (t_stack *stack)
{
	while (stack -> next != NULL)
	{
		ft_printf("%d ", stack->val);
		stack = stack -> next;
	}
	ft_printf("%d ", stack->val);
	ft_printf("\n");
}

void	print_stack_index (t_stack *stack)
{
	while (stack -> next != NULL)
	{
		ft_printf("%d ", stack->val);
		ft_printf("%d ", stack->index);
		ft_printf("\n");
		stack = stack -> next;
	}
	ft_printf("%d ", stack->val);
	ft_printf("%d ", stack->index);
	ft_printf("\n\n");
}

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

int pa(t_stack **a_stack, t_stack **b_stack)
{
    if (*b_stack == NULL)
        return 0;

    t_stack *new = malloc(sizeof(t_stack));
    if (new == NULL)
        return 0;

    new->val = (*b_stack)->val;
    new->index = (*b_stack)->index;

    new->next = (*a_stack);
    (*a_stack) = new;
    (*b_stack) = (*b_stack)->next;

    return 1;
}

int pb(t_stack **a_stack, t_stack **b_stack)
{
    if (*a_stack == NULL)
        return 0;

    t_stack *new = malloc(sizeof(t_stack));
    if (new == NULL)
        return 0;

    new->val = (*a_stack)->val;
    new->index = (*a_stack)->index;

    new->next = (*b_stack);
    (*b_stack) = new;
    (*a_stack) = (*a_stack)->next;

    return 1;
}
int rra (t_stack **a_stack)
{
	t_stack	*last_node;
	t_stack *second_last_node;

	last_node = *a_stack;//ok
	second_last_node = NULL;//ok
	while (last_node -> next != NULL)
	{
		second_last_node = last_node;
		last_node = last_node -> next;
	}
	last_node -> next = *a_stack;
	*a_stack = last_node;
	second_last_node -> next = NULL;
    return 1;
}
int ra(t_stack **a_stack)
{
    if (*a_stack == NULL || (*a_stack)->next == NULL)
        return(-1);

    t_stack *first_node = *a_stack;
    *a_stack = (*a_stack)->next;

    t_stack *current_node = *a_stack;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = first_node;
    first_node->next = NULL;
	return(0);
}
int rb(t_stack **b_stack)
{
    t_stack *first_node;
	t_stack *current_node;
    if (*b_stack == NULL || (*b_stack)->next == NULL)
		return(-1);
	first_node = *b_stack;
    *b_stack = (*b_stack)->next;
	current_node = *b_stack;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = first_node;
    first_node->next = NULL;
	return(0);
}
int sa(t_stack **a_stack)
{
	int swap;
    int swap_index;
	if (*a_stack == NULL || (*a_stack)->next == NULL)
        return (-1);
	 swap = (*a_stack)->val;
	 swap_index = (*a_stack)->index;
    (*a_stack)->val = (*a_stack)->next->val;
    (*a_stack)->index = (*a_stack)->next->index;

    (*a_stack)->next->val = swap;
    (*a_stack)->next->index = swap_index;
	return (0);
}
int sort_3(t_stack **a_stack)
{
    t_stack *stack;

    int pos[3];
    int i;

	i = 0;
	stack = *a_stack;
    if (!stack)
        return(-1);

    while (stack && i < 3)
    {
        pos[i] = stack->index;
        stack = stack->next;
        i++;
    }

    if (pos[0] < pos[1] && pos[1] < pos[2])
        return(0);
    else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] > pos[0])
        sa(a_stack);
    else if (pos[0] > pos[1] && pos[1] > pos[2])
    {
        sa(a_stack);
        rra(a_stack);
	}
    else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] < pos[0])
        ra(a_stack);
    else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] > pos[0])
    {
        sa(a_stack);
        ra(a_stack);
    }
    else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] < pos[0])
        rra(a_stack);
return(0);
}

int sort_4(t_stack **a_stack, t_stack **b_stack)
{
	if (!(*a_stack) || !(*b_stack))
		return (-1);
	while ((*a_stack) -> index != 1)
			ra(a_stack);
	pb(a_stack, b_stack);
	sort_3(a_stack);
	pa(a_stack,b_stack);
	return (0);
}
int sort_5(t_stack **a_stack, t_stack **b_stack)
{
	if (!(*a_stack) || !(*b_stack))
		return (-1);
	while ((*a_stack) -> index != 1)
		ra(a_stack);
	pb(a_stack,b_stack);
	while ((*a_stack) -> index != 2)
			ra(a_stack);
	pb(a_stack,b_stack);
	sort_3(a_stack);
	while ((*b_stack) -> index != 2)
		rb(b_stack);
	pa(a_stack,b_stack);
	pa(a_stack,b_stack);
	return(0);
}
int main(int ac, char **av)
{
    t_stack *a_stack;
	t_stack *b_stack;

    a_stack = parse_stack(av, ac);
	b_stack = parse_stack(NULL,0);
	index_stack(a_stack,ac);
	print_stack_index(a_stack);
	// sort_4(&a_stack, &b_stack);
	sort_5(&a_stack,&b_stack);
	print_stack_index(a_stack);

	return(0);
}
