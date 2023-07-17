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
int	pb(t_stack **b_stack, t_stack **a_stack)
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
	/* if you pass variables opposite it works lol, good thinking Ester <3 */
}