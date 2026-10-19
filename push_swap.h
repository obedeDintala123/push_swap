/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalata <cpalata@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:18:49 by cpalata           #+#    #+#             */
/*   Updated: 2026/10/19 20:48:20 by cpalata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdbool.h>

typedef struct no
{
	int			value;
	struct no	*next;
}	t_no;

int		ft_iswhitespace(char *str);
int		len_stack(t_no pilha);
int		ft_count_opt(char **argv);
int		ft_validate_opt(char **argv);
int		ft_validate_nbr(char **argv);
int		ft_has_space(char *str);
void	ft_free_array(char **array);
char	**ft_get_nbr(char *str);
char	**ft_get_opt(char **argv);
int		ft_has_nbr(char **argv);
int		ft_ternary(bool cond1, bool cond2,
			int value1, int value2);
int		ft_is_flag(char *str);
int		ft_is_opt(char *str, char *opt);
int		ft_is_mode(char *str);

typedef struct no
{
	int			value;
	int			index;
	struct no	*next;
}	t_no;

void	push_a(t_no **pilha_a, t_no **pilha_b);
void	push_b(t_no **pilha_b, t_no **pilha_a);
void	rotate_a(t_no **pilha);
void	rotate_b(t_no **pilha);
void	rr_rotate(t_no **pilha_a, t_no **pilha_b);
void	reverse_a(t_no **pilha_a);
void	reverse_b(t_no **pilha_b);
void	rrr_reverse(t_no **pilha_a, t_no **pilha_b);
void	sa(t_no **pilha);
void	sb(t_no **pilha);
void	ss(t_no **pilha_a, t_no **pilha_b);

t_no	*ft_create_stack(char **values);
void	ft_chose_method(t_no *pilha_a);
void	ft_free_stack(t_no *str);

#endif
