#include "push_swap.h"
#include <stdio.h>

char **ft_get_opt(char **argv)
{
    int i;
    int j;
    char **options;

    options = malloc((ft_count_opt(argv) + 1) * sizeof(char *));
    if (!options)
        return (NULL);
    i = 0;
    j = 0;
    while (argv[i])
    {
        if (argv[i][0] == '-' && ft_isalpha(argv[i][1]))
            options[j++] = argv[i];
        else if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
            options[j++] = argv[i];
        i++;
    }
    options[j] = NULL;
    return (options);
}

int ft_check_opt(char **options, char **valid_opt)
{
    int i;
    int j;

    i = 0;
    while (options[i])
    {
        j = 0;
        while (valid_opt[j])
        {
            if (ft_strncmp(options[i], valid_opt[j],
                           ft_strlen(valid_opt[j]) + 1) == 0)
                break;
            j++;
        }
        if (!valid_opt[j])
            return (1);
        i++;
    }
    return (0);
}

int ft_validate_opt(char **argv)
{
    char **options;
    char **valid_opt;

    valid_opt = (char *[]){
        "--simple",
        "--medium",
        "--complex",
        "--adaptive",
        "--bench",
        NULL};
    if (ft_count_opt(argv) > 2)
        return (-1);
    options = ft_get_opt(argv);
    if (!options)
        return (1);
    if (ft_check_opt(options, valid_opt) == 1)
        return (-1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    if (ft_validate_opt(argv) == -1)
        ft_putstr_fd("Error\n", 2);
    else
        ft_printf("%d", ft_count_opt(argv));
    return (0);
}