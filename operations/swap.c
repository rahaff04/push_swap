#include "../push_swap.h"

void   sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    second = (*a)->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    write (1, "sa\n", 3);
}

void sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    write (1, "sb\n", 3);
}