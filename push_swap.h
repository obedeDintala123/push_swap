
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int	ft_iswhitespace(char *str);
int ft_count_opt(char **argv);
int ft_count_nbr(char **argv);
int ft_validate_opt(char **argv);
int ft_validate_nbr(char **argv);
int ft_has_space(char *str);
void ft_free_array(char **array);
char **ft_get_nbr(char *str);
char **ft_get_opt(char **argv);
int ft_has_nbr(char **argv);

#endif
