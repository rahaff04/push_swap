#include "../push_swap.h"

int get_size(t_stack *a)
{
    int size;

    size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}

int find_min(t_stack *a)
{
    int min;

    if (!a)
        return (0);
    min = a->value;
    while (a)
    {
        if (a->value < min)
            min = a->value;
        a = a->next;
    }
    return (min);
}

int find_max(t_stack *a)
{
    int max;

    if (!a)
        return (0);
    max = a->value;
    while (a)
    {
        if (a->value > max)
            max = a->value;
        a = a->next;
    }
    return (max);
}

int get_index(t_stack *a, int v)
{
    int i;

    i = 0;
    while (a)
    {
        if (a->value == v)
            return (i);
        i++;
        a = a->next;
    }
    return (-1);
}