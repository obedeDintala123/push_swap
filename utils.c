#include "push_swap.h"

int	ft_iswhitespace(char *str)
{
	while (*str)
	{
		if (!(*str == 32 || (*str >= 9 && *str <= 13)))
			return (1);
		str++;
	}
	return (0);
}

int ft_count_opt(char **argv)
{
    int i;
    int count;

    i = 1;
    count = 0;
    while (argv[i])
    {
        if (argv[i][0] == '-' && ft_isalpha(argv[i][1]))
            count++;
        else if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
            count++;
        i++;
    }
    return (count);
}

