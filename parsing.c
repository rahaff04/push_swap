#include "push_swap.h"

static int write_error(void)
{
    write(2, "Error\n", 6);
    return (0);
}

static void free_split(char **s)
{
    int i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
}

static int check_split(char *num_str, t_stack **a)
{
    long n;
    t_stack *node;

    if (!ft_is_number(num_str))
        return (0);
    n = ft_atol(num_str);
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    if (has_duplicate(*a, (int)n))
        return (0);
    node = s_new((int)n);
    if (!node)
        return (0);
    add_back(a, node);
    return (1);
}

int parse_split(char *av, t_stack **a)
{
    char **num;
    int i;

    num = ft_split(av, ' ');
    if (!num)
        return (write_error());
    i = 0;
    while (num[i])
    {
        if (!check_split(num[i], a))
        {
            free_split(num);
            return (write_error());
        }
        i++;
    }
    free_split(num);
    return (1);
}


int     parse(int ac, char **av, t_stack **a)
{
    long n;
    int i;

    i = 1;
    while (i < ac)
    {
        if (!ft_is_number(av[i]))
            return (write_error());
        n = ft_atol(av[i]);
        if (n < INT_MIN || n > INT_MAX)
            return (write_error());
        if (has_duplicate(*a, (int)n))
            return (write_error());
        add_back(a, s_new((int)n));
        i++;
    }
    return (1);
}




