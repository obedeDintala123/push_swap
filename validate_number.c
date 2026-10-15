#include "push_swap.h"

int ft_has_nbr(char **argv)
{
    int i;
    int j;

    i = (ft_count_opt(argv) == 1) ? 2 :
        (ft_count_opt(argv) == 2) ? 3 : 1;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int ft_isvalid_nbr(char *str)
{
    long    value;
    int     sign;

    value = 0;
    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
        return (0);
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        value = value * 10 + (*str - '0');
        if ((sign == 1 && value > 2147483647L)
            || (sign == -1 && value > 2147483648L))
            return (0);
        str++;
    }
    return (1);
}

char **ft_get_nbr(char *str)
{
    int i;
    char **nbr;

    if (!ft_iswhitespace(str))
        return (NULL);
    nbr = ft_split(str, ' ');
    if (!nbr)
        return (0);
    i = 0;
    while (nbr[i])
    {
        if (!ft_isvalid_nbr(nbr[i]))
        {
            ft_free_array(nbr);
            return (NULL);
        }
        i++;
    }
    return (nbr);
}

static int ft_has_duplicate(char **argv, int i, int j, char *nbr)
{
    int k;
    int l;
    char **values;

    k = (ft_count_opt(argv) == 1) ? 2 :
        (ft_count_opt(argv) == 2) ? 3 : 1;
    while (k <= i)
    {
        values = ft_get_nbr(argv[k]);
        if (!values)
            return (1);
        l = 0;
        while (values[l] && (k < i || l < j))
        {
            if (ft_atoi(values[l]) == ft_atoi(nbr))
                return (ft_free_array(values), 1);
            l++;
        }
        ft_free_array(values);
        k++;
    }
    return (0);
}

int ft_validate_nbr(char **argv)
{
    int i;
    int j;
    char **values;

    i = (ft_count_opt(argv) == 1) ? 2 :
        (ft_count_opt(argv) == 2) ? 3 : 1;
    while (argv[i])
    {
        values = ft_get_nbr(argv[i++]);
        if (!values)
            return (ft_free_array(values), 0);
        j = 0;
        while (values[j])
        {
            if (ft_has_duplicate(argv, i - 1, j, values[j]) || !ft_isvalid_nbr(values[j]))
            {
                ft_free_array(values);
                return (0);
            }
            j++;
        }
        ft_free_array(values);
    }
    return (1);
}
