/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:18:26 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/12 22:35:21 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define ADAPTIVE 0
# define SIMPLE   1
# define MEDIUM   2
# define COMPLEX  3

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
} 						t_stack_node;

typedef struct s_bench
{
	int		enabled;
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

int				stack_size(t_stack_node *st);
t_stack_node	*create_stack(char **av, int ac);
void			get_rank(t_stack_node *sa, int size);
int				get_chunk_size(int size, int strategy);
void			simple_sort(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			complex_sort(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b, int strategy, t_bench *bench);
int				get_node_position(t_stack_node *stack, t_stack_node *target);
int				is_bench(char *arg);
int				has_bench(char **argv);
void			counting_bench(t_bench *bench, char *op);
void			creating_bench(t_bench *bench, int enabled);
void			bench_setup(t_bench *bench, char **argv);
void			bench_results(t_bench *bench);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			adaptive_sort(t_stack_node **a, t_stack_node **b, int strategy, t_bench *bench);
void			sort_short(t_stack_node **a, t_stack_node **b, t_bench *bench);
double			calc_disorder(t_stack_node *stack_a);


int				ft_parse_flags(char **argv, int *strategy, t_bench *bench);
int				ft_atoi(const char *nptr);
long			ft_atol(char *str);
void			ft_check_args(char **argv, int start);
void			ft_check_duplicates(char **argv, int start);

t_stack_node	*find_max_node(t_stack_node *stack);
void			push_chunks_b(t_stack_node **stack_a,t_stack_node **stack_b, int chunk, t_bench *bench);
int				get_last_match(t_stack_node *stack, int low, int high);
int				get_first_match(t_stack_node *stack, int low, int high);



void			ft_putstr(char *s);
void			free_stack(t_stack_node **lst);
void			error(t_stack_node **a, t_stack_node **b);
void			error_parseo(void);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			rotate_to_top(t_stack_node **stack_a, int top_pos, int bot_pos, t_bench *bench);

void			sa(t_stack_node **a, t_bench *bench);
void			sb(t_stack_node **b, t_bench *bench);
void			ss(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pa(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pb(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			ra(t_stack_node **a, t_bench *bench);
void			rb(t_stack_node **b, t_bench *bench);
void			rr(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			rra(t_stack_node **a, t_bench *bench);
void			rrb(t_stack_node **b, t_bench *bench);
void			rrr(t_stack_node **a, t_stack_node **b, t_bench *bench);

#endif
