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
void    stack_add_back(t_stack *lst, int content,int index)
{
    t_stack *old;
    t_stack *new;
    new = ft_calloc(sizeof(t_stack), 1);
    if (new == NULL)
        return ;
    new->val = content;
	new ->index = index;
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
	ft_printf("\n");
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
			stack_add_back(stack, ft_atoi(av[i]), 0);
        i++;
    }
    return (stack);
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
int is_sorted(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> index < stack -> next -> index)
			stack = stack -> next;
		else 
			{
				ft_printf("Stack is nicht sorted!");
				return (0);
			}
	}
	ft_printf("Stack is sorted!");
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
    stack = head;
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
}

int main(int ac, char **av)
{
    t_stack *a_stack;
 	//t_stack *b_stack;
	//char		**bv;

	//bv = ft_calloc(4,sizeof(char **));
	//bv[1] = "10";
	//bv[2] = "11";
	//bv[3] = "9";
    a_stack = parse_stack(av, ac);
	//b_stack = parse_stack(bv, ac);
	index_stack(a_stack,ac);
	print_stack_index(a_stack);
	//rra(&a_stack);
	//print_stack_index(a_stack);
	is_sorted(a_stack);
	//print_stack(b_stack);
	//ra(a_stack);
	//print_stack(a_stack);
	//print_stack(b_stack);	

	return(0);
}