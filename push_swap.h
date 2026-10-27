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

typedef struct no
{
	int			value;
	int			index;
	struct no	*next;
}	t_no;

typedef struct s_bench
{
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_bench;

typedef struct s_disorder
{
	long	mistakes;
	long	total_pairs;
	float	ratio;
}	t_dis;

typedef struct s_sort_run
{
	t_no		**pilha_a;
	t_no		*pilha_b;
	t_bench		bench;
	t_dis		disorder;
	char		*mode;
	char		*strategy;
	char		*complexity;
	int			size;
	int			bench_enabled;
	int			adaptive;
}	t_sort_run;

int		ft_iswhitespace(char *str);
int		len_stack(t_no *pilha);
int		ft_count_opt(char **argv);
int		ft_validate_opt(char **argv);
int		ft_validate_nbr(char **argv);
int		ft_has_space(char *str);
void	ft_free_array(char **array);
char	**ft_get_nbr(char *str);
char	**ft_get_opt(char **argv);
int		ft_has_nbr(char **argv);
int		ft_is_flag(char *str);
int		ft_is_opt(char *str, char *opt);
int		ft_is_mode(char *str);
int		ft_first_nbr_idx(char **argv);
int		ft_count_values(char **values, int size);

int		get_chunk_size(int size);
int		raiz(int n);
int		get_max_index_position(t_no *stack);
int		get_max_bits(int size);
void	sign_index(t_no *pilha);
void	push_chunks(t_no **a, t_no **b, int chunk_size, t_bench *bench);
void	push_back_to_a(t_no **a, t_no **b, t_bench *bench);
void	radix_sort(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
void	chunk_sort(t_no **a, t_no **b, t_bench *bench);
void	select_sort(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
void	sort_small(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
t_dis	compute_disorder(t_no *stack);
void	bench_count(t_bench *bench, char *operation);
void	bench_reset(t_bench *bench);
void	bench_report(t_sort_run *run);

void	push_a(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
void	push_b(t_no **pilha_b, t_no **pilha_a, t_bench *bench);
void	rotate_a(t_no **pilha, t_bench *bench);
void	rotate_b(t_no **pilha, t_bench *bench);
void	rr_rotate(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
void	reverse_a(t_no **pilha_a, t_bench *bench);
void	reverse_b(t_no **pilha_b, t_bench *bench);
void	rrr_reverse(t_no **pilha_a, t_no **pilha_b, t_bench *bench);
void	sa(t_no **pilha, t_bench *bench);
void	sb(t_no **pilha, t_bench *bench);
void	ss(t_no **pilha_a, t_no **pilha_b, t_bench *bench);

void	ft_chose_method(t_no **pilha_a, char **argv);
void	ft_free_stack(t_no *str);
int		ft_push_value(t_no **stack, int value);

#endif
