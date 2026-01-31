#include "../push_swap.h"

static int find_max_index(t_stack *a)
{
    int max_index;

    max_index = -1;
    while (a)
    {
        if (a->index > max_index)
            max_index = a->index;
        a = a->next;
    }
    return (max_index);
}


static int bits_count(t_stack *a)
{
    int max;
    int bits;

    max = find_max_index(a);
    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int j;
    int size;
    int bits;

    size = get_size(*a);
    bits = bits_count(*a);
    i = 0;
    while (i < bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (get_size(*b) > 0)
            pa(a, b);
        i++;
    }
}
