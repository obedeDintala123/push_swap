/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obdintal <obdintal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 11:00:05 by obdintal          #+#    #+#             */
/*   Updated: 2026/10/19 11:15:25 by obdintal         ###   ########.fr       */
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
	int		i;
	char	**valid_comb;
	char	*received_comb;

	valid_comb = (char *[]){
		"--simple--bench",
		"--medium--bench",
		"--complex--bench",
		"--adaptive--bench",
		"--bench--simple",
		"--bench--medium",
		"--bench--complex",
		"--bench--adaptive", NULL};
	received_comb = ft_strjoin(options[0], options[1]);
	if (!received_comb)
		return (0);
	i = 0;
	while (valid_comb[i])
	{
		if (ft_strncmp(valid_comb[i],
			received_comb, ft_strlen(received_comb)) == 0)
		{
			free(received_comb);
			return (1);
		}
		i++;
	}
	free(received_comb);
	return (0);
}

static int	ft_find_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if ((argv[i][0] == '-' && ft_isalpha(argv[i][1]))
			|| (argv[i][0] == '-' && argv[i][1] == '-'
				&& ft_isalpha(argv[i][2])))
		{
			j = i + 1;
			while (argv[j])
			{
				if (((argv[j][0] == '-' && ft_isalpha(argv[j][1]))
					|| (argv[j][0] == '-' && argv[j][1] == '-'
						&& ft_isalpha(argv[j][2])))
						&& ft_strlen(argv[i]) == ft_strlen(argv[j])
						&& ft_strncmp(argv[i],
							argv[j], ft_strlen(argv[i])) == 0)
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
	char	**valid_opt;

	valid_opt = (char *[]){
		"--simple",
		"--medium",
		"--complex",
		"--adaptive",
		"--bench",
		NULL};
	options = ft_get_opt(argv);
	if (!options)
		return (0);
	if (ft_count_opt(argv) == 1
		&& (!ft_check_opt(options, valid_opt) || ft_find_duplicates(argv)))
	{
		free (options);
		return (0);
	}
	if (ft_count_opt(argv) == 2
		&& (!ft_check_opt_comb(options) || ft_find_duplicates(argv)))
	{
		free (options);
		return (0);
	}
	free (options);
	return (1);
}
