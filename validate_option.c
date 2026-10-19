/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:00:05 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 14:45:00 by obdintal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_get_opt(char **argv)
{
	int		i;
	int		j;
	char	**options;

	options = malloc((ft_count_opt(argv) + 1) * sizeof(char *));
	if (!options)
		return (NULL);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-' && ft_isalpha(argv[i][1]))
			options[j++] = argv[i];
		else if (argv[i][0] == '-'
			&& argv[i][1] == '-' && ft_isalpha(argv[i][2]))
			options[j++] = argv[i];
		i++;
	}
	options[j] = NULL;
	return (options);
}

static int	ft_check_opt(char **options, char **valid_opt)
{
	int	i;
	int	j;

	i = 0;
	while (options[i])
	{
		j = 0;
		while (valid_opt[j])
		{
			if (ft_strncmp(options[i], valid_opt[j],
					ft_strlen(valid_opt[j]) + 1) == 0)
				break ;
			j++;
		}
		if (!valid_opt[j])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_opt_comb(char **options)
{
	if (ft_is_opt(options[0], "--bench"))
		return (ft_is_mode(options[1]));
	if (ft_is_opt(options[1], "--bench"))
		return (ft_is_mode(options[0]));
	return (0);
}

static int	ft_find_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_is_flag(argv[i]))
		{
			j = i + 1;
			while (argv[j])
			{
				if (ft_is_flag(argv[j]) && !ft_strncmp(argv[i],
						argv[j], ft_strlen(argv[i]) + 1))
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_validate_opt(char **argv)
{
	char	**options;
	int		count;
	int		valid;

	options = ft_get_opt(argv);
	if (!options)
		return (0);
	count = ft_count_opt(argv);
	valid = 1;
	if (count == 1)
		valid = ft_check_opt(options, (char *[]){"--simple", "--medium",
				"--complex", "--adaptive", "--bench", NULL});
	else if (count == 2)
		valid = ft_check_opt_comb(options);
	free(options);
	return (valid && !ft_find_duplicates(argv));
}
