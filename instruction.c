#include "push_swap.h"

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


void  ra(t_stack **a)
{
    t_stack *first;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    *a = first->next;
    first->next = NULL;
    last = *a;
    while (last->next)
        last = last->next;
    last->next = first;
    write (1, "ra\n", 3);
}

void  rra(t_stack **a)
{
    t_stack *prev;
    t_stack *last;

    if (!a || !*a || !(*a)->next)
        return ;
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    write (1, "rra\n", 4);
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

void rb(t_stack **b)
{
    t_stack *first;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    *b = first->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    write (1, "rb\n", 3);
}
void rrb(t_stack **b)
{
    t_stack *prev;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return ;
    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    write (1, "rrb\n", 4);
}
void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!b || !*b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    write (1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!a || !*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write (1, "pb\n", 3);
}