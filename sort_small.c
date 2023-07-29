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
