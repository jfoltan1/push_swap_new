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
int ra(t_stack *a_stack)
{
    int first_val; 
    int first_index;
	first_val = a_stack->val;
	first_index = a_stack->index;

        while (a_stack->next != NULL)
    {
        a_stack->val = a_stack->next->val;
        a_stack->index = a_stack->next->index;
        a_stack = a_stack->next;
    }
    a_stack->val = first_val;
    a_stack->index = first_index;
    a_stack->next = NULL;

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

int	sa(t_stack *a_stack)
{
	int swap;
	int swap_index;
	t_stack *head;
	head = a_stack;
	if (a_stack -> next == NULL)
		return(0);
	swap = a_stack -> val;
	swap_index = a_stack -> index;
	a_stack -> val = a_stack -> next -> val;
	a_stack -> index = a_stack -> next -> index;

	a_stack -> next -> val = swap;
	a_stack -> next -> index = swap_index;
	a_stack = head;
	return(1);
}
int sort_3(t_stack **a_stack) 
{
	if (!(*a_stack))
		return -1;

	int pos[3];
	int i = 0;
	t_stack *stack = *a_stack;

	while (stack->next != NULL) 
	{
		pos[i] = stack->index;
		stack = stack->next;
		i++;
	}
	pos[i] = stack->index;

	stack = *a_stack;
	if (pos[0] < pos[1] && pos[1] < pos[2])
		return (0);
	else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] > pos[0])
		sa(*a_stack);
	else if (pos[0] > pos[1] && pos[1] > pos[2])
	{
		sa(stack);
		rra(a_stack);
	}
	else if (pos[0] > pos[1] && pos[1] < pos[2] && pos[2] < pos[0])
		ra(*a_stack);
	else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] > pos[0])
	{
		sa(stack);
		ra(*a_stack);
	}
	else if (pos[0] < pos[1] && pos[1] > pos[2] && pos[2] < pos[0])
		rra(a_stack);

	return (0);
}
t_stack *find_smallest_node(t_stack *stack) {
    if (stack == NULL) {
        return NULL; // Stack is empty
    }

    t_stack *smallest_node = stack;
    int smallest_value = stack->index;

    while (stack != NULL) {
        if (stack->index < smallest_value) {
            smallest_node = stack;
            smallest_value = stack->index;
        }
        stack = stack->next;
    }

    return smallest_node;
}
int sort_4(t_stack **a_stack, t_stack **b_stack)
{
	t_stack *smallest_node;
	int smallest_value;
	
	if (!(*a_stack))
		return (-1);
	
	smallest_node = *a_stack;
	smallest_value = (*a_stack)->index;
	t_stack *stack = *a_stack;

	while (stack != NULL)
	{
		if (stack->index < smallest_value) 
		{
			smallest_node = stack;
			smallest_value = stack->index;
		}
		stack = stack->next;
	}

	while ((*a_stack) != smallest_node)
	{
		sa(*a_stack);
	}

	pb(b_stack, a_stack);
	sort_3(a_stack);
	pa(a_stack,b_stack);
	return (0);
}
int main(int ac, char **av)
{
    t_stack *a_stack;
	t_stack *b_stack;
	
    a_stack = parse_stack(av, ac);
	b_stack = malloc(sizeof(t_stack));
	index_stack(a_stack,ac);
	print_stack_index(a_stack);
	//sa(a_stack);
	//rra(&a_stack);
	sort_4(&a_stack);

	print_stack_index(a_stack);
	
	return(0);
}