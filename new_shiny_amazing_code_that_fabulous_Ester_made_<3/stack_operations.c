#include "push_swap.h"

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
