#include "push_swap.h"

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
    //printf("number being stacked is %i\n", content);
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
			stack_add_back(stack, ft_atoi(av[i]));
        i++;
    }
    return (stack);
}
int ra(t_stack *a_stack)
{
	
}
int main(int ac, char **av)
{
    t_stack *a_stack;
 	t_stack *b_stack;
	char		**bv;

	bv = ft_calloc(4,sizeof(char **));
	bv[1] = "10";
	bv[2] = "11";
	bv[3] = "9";
    a_stack = parse_stack(av, ac);
	b_stack = parse_stack(bv, ac);
	print_stack(a_stack);
	print_stack(b_stack);
	ra(a_stack);
	print_stack(a_stack);
	//print_stack(b_stack);	

	return(0);
}