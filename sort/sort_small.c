#include "../push_swap.h"

void sort_2(t_stack **a)
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

    min = find_min(*a);
    i = get_index(*a, min);
    size = get_size(*a);
    while ((*a)->value != min)
    {
        if (i <= size / 2)
            ra(a);
        else
            rra(a);
        i = get_index(*a, min);
    }
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
{
    int min;
    int i;
    int size;

    min = find_min(*a);
    i = get_index(*a, min);
    size = get_size(*a);
    while ((*a)->value != min)
    {
        if (i <= size / 2)
            ra(a);
        else
            rra(a);
        i = get_index(*a, min);
    }
    pb(a, b);
    sort_4(a, b);
    pa(a, b);
}

