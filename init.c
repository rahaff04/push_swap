#include "push_swap.h"

#include "push_swap.h"

static void reset_index(t_stack *a)
{
    t_stack *tmp = a;
    while (tmp)
    {
        tmp->index = -1;
        tmp = tmp->next;
    }
}

static void assign_index(t_stack *a)
{
    int size = get_size(a);
    int i;

    for (i = 0; i < size; i++)
    {
        t_stack *tmp = a;
        t_stack *min_node = NULL;
        int min = INT_MAX;

        while (tmp)
        {
            if (tmp->index == -1 && tmp->value < min)
            {
                min = tmp->value;
                min_node = tmp;
            }
            tmp = tmp->next;
        }
        if (min_node)
            min_node->index = i;
    }
}
static void set_index(t_stack *a)
{
    reset_index(a);
    assign_index(a);
}

static int     parse_args(int ac , char **av, t_stack **a)
{
    if (ac < 2)
        return (1);
    if (ac == 2)
    {
        if (!parse_split(av[1], a))
            return (0);
    }
    else
    {
        if (!parse(ac, av, a))
            return (0);
    }
    return (1);
}

int init_stack(int ac, char **av, t_stack **a)
{
    if (!parse_args(ac, av, a))
        return (0);
    if (get_size(*a) > 5)
        set_index(*a);
    return (1);
}