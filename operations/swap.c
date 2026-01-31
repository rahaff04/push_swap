#include "../push_swap.h"

static void swap(t_stack **s)
{
    t_stack *tmp;

    if (!s || !*s || !(*s)->next)
        return;
    tmp = (*s)->next;
    (*s)->next = tmp->next;
    tmp->next = *s;
    *s = tmp;
}

void   sa(t_stack **a)
{
    swap(a);
    write (1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap(b);
    write (1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write (1, "ss\n", 3);
}