#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int size;
    size = 1;
    while (stack->next != NULL)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}
int argcheck(char **av, int ac)
{
    int i;
    int j;
    i = 1;
    if (ac < 3)
        exit (1);
    //check for non-digits and dups
    //missing limits for int size
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
            {
                ft_printf("Error1\n");
                exit(2);
            }
            j++;
        }
        j = 0;
        while (j < i)
        {
            if (ft_atoi(av[j]) == ft_atoi(av[i]))
            {
                ft_printf("Error2\n");
                exit(2);
            }
            j++;
        }
        i++;
    }
    return(1);
}
t_stack *radix_sort(t_stack *a, t_stack *b)
{
    int max_bits;
    int i;
    int j;
    int num;
    int size;
    i = 0;
    j = 0;
    max_bits = 0;
    size = stack_size(a);
    while ((size >> max_bits) != 0)
        max_bits++;
    while (i < max_bits)
    {
        while (j < size)
        {
            num = a->index;
            if (((num >> i)&1) == 1)
                rotate(a, "ra");
            else
                push(&b, &a, "pb");
            j++;
        }
        j = 0;
        i++;
        while (b != NULL)
            push(&a, &b, "pa");
    }
    return (a);
}
int main(int ac, char **av)
{
    t_stack *a_stack;
    t_stack *b_stack;
    int         size;
    size = ac - 1;
    a_stack = parse_stack(av, size);
    b_stack = parse_stack(NULL, 0);
    index_stack(a_stack, ac);
    //print_stack(a_stack);
    //print_index(a_stack);
	a_stack = radix_sort(a_stack, b_stack);
    free(a_stack);
    free(b_stack);
    return(0);
}
