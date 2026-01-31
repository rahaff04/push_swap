#include "../push_swap.h"

static void move_to_top(t_stack **a,t_stack **b, int v)
{
    int size;

    size = get_size(*a);
    while ((*a)->index != v)
    {
        if (!*b)
        {
            if (get_index(*a, v) <= size / 2)
                ra(a);
            else
                rra(a);
        }
        else
        {
            if (get_index(*a, v) <= size / 2)
                rr(a, b);
            else
                rrr(a, b);
        }
    }
}


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

    min = find_min(*a);
    move_to_top(a, b, min);
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

void sort_5(t_stack **a, t_stack **b)
{
    int min;

    min = find_min(*a);
    move_to_top(a, b, min);
    pb(a, b);
    sort_4(a, b);
    pa(a, b);
}


