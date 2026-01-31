#include "push_swap.h"

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

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (!parse_args(ac, av, &a))
        return (1);
    if (get_size(a) <= 5)
    {
        if (get_size(a) == 2)
            sort_2(&a);
        else if (get_size(a) == 3)
            sort_3(&a);
        else if (get_size(a) == 4)
            sort_4(&a, &b);
        else if (get_size(a) == 5)
            sort_5(&a, &b);
    }
    // else
    //     sort_large(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
