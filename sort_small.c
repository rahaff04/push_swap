#include "push_swap.h"

void  sort_2(t_stack **a)
{
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void sort_3(t_stack **a)
{
    int max;

    max = find_max(*a);
    if ((*a)->value == max)
        ra(a);
    else if ((*a)->next->value == max)
        rra(a);
    sort_2(a); 
}

void sort_4(t_stack **a, t_stack **b)
{
    int min;
    int i;
    int size;

    size = get_size(*a);
    min = find_min(*a);
    i = get_index(*a, min);
    while ((*a)->value != min)
    {
        if (i <= size / 2)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
{
    while ((*a)->value != find_min(*a))
    {
        if (get_index(*a, find_min(*a)) <= get_size(*a) / 2)
            ra(a);
        else
            rra(a);
    }
    pb(a, b);
    sort_4(a, b);
    pa(a, b);
}

