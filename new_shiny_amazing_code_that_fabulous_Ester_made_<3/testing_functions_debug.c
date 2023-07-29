#include "push_swap.h"

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
        ft_printf("val: %d\n", stack->val);
        stack = stack -> next;
        i++;
    }
    ft_printf("val: %d\n", stack->val);
    ft_printf("\n");
}
void    print_index (t_stack *stack)
{
    int i;
    int size;
    if (!stack)
        return ;
    i = 1;
    size = stack_size(stack);
    while (i < size)
    {
        ft_printf("index: %d\n", stack->index);
        stack = stack -> next;
        i++;
    }
    ft_printf("index: %d\n", stack->index);
    ft_printf("\n");
}
