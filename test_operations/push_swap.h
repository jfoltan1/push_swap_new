#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include <stdio.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include <unistd.h>
#include <stddef.h>

typedef struct s_stack
{
    int             val;
    int             index;
    struct s_stack  *next;
}               t_stack;
int swap(t_stack *stack);
int push(t_stack *a_stack, t_stack *b_stack);
int rotate(t_stack *stack);
int rev_rotate(t_stack *stack);
int sa(t_stack *a_stack);
int sb(t_stack *b_stack);
int ss(t_stack *a_stack, t_stack *b_stack);
int pa(t_stack **a_stack, t_stack **b_stack);
int pb(t_stack **b_stack, t_stack **a_stack);
int ra(t_stack *a_stack);
int rb(t_stack **b_stack);
int rra(t_stack **a_stack);
int rrb(t_stack *b_stack);
int rrr(t_stack *a_stack, t_stack *b_stack);
t_stack *stack_last(t_stack *lst);
void    stack_add_back(t_stack *lst, int content, int index);
#endif