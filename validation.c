#include "push_swap.h"

static int	ft_validate_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (1);
		if (ft_iswhitespace(argv[i]) == 0)
			return (1);
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == 32 && argv[i][j + 1])
				j++;
			if ((argv[i][j] == 43 || argv[i][j] == 45)
			&& ft_isdigit(argv[i][j + 1]))
				j++;
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != 32)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isvalid(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	return (ft_validate_input(argv));
}
