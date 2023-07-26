int	sa(t_stack *a_stack)
{
	int swap;

	if (a_stack -> next == NULL)
		return(0);
	swap = a_stack -> val;
	a_stack -> val = a_stack -> next -> val;
	a_stack -> next -> val = swap;
	/* do  I need to free swap?  */
	return(1);
}
int	sb(t_stack *b_stack)
{
	int swap;

	if (b_stack -> next == NULL)
		return(0);
	swap = b_stack -> val;
	b_stack -> val = b_stack -> next -> val;
	b_stack -> next -> val = swap;
	/* do  I need to free swap?  */
	return(1);
}
int	ss(t_stack *a_stack, t_stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}
int	pa(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*new;

	if ((*b_stack) == NULL)
		return (0); 
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->val = (*b_stack)->val;
	new->next = (*a_stack);
	(*a_stack) = new;
	(*b_stack) = (*b_stack)->next;

	return (1);
	/* when calling function: pa(&a_stack, &b_stack); */
	/*  you're trying to update the stack pointers a_stack and b_stack within the pa function. However, in C, function parameters are passed by value, which means any changes made to those parameters inside the function will not affect the original variables in the calling code. To update the stack pointers correctly, you need to pass pointers to pointers as function parameters. Here's an updated version of the function declaration: */
}
int	pb(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*new;

	if ((*a_stack) == NULL)
		return (0); 
	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->val = (*a_stack)->val;
	new->next = (*b_stack);
	(*b_stack) = new;
	(*a_stack) = (*a_stack)->next;

	return (1);
	/* if you pass variables opposite it works lol, good thinking Ester <3 */
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

	last_node = *a_stack;
	second_last_node = NULL;
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