/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:18:26 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/15 19:14:15 by lumacko          ###   ########.fr       */
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

/* adaptive */
void			adaptive_sort(t_stack_node **a, t_stack_node **b, int strategy, t_bench *bench);

/* bench helpers */
int				is_bench(char *arg);
int				has_bench(char **argv);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);

/* bench text */
void			bench_results(t_bench *bench);

/* bench */
void			creating_bench(t_bench *bench, int enabled);
void			counting_bench(t_bench *bench, char *op);
void			bench_setup(t_bench *bench, char **argv);

/* calc disorder */
double			calc_disorder(t_stack_node *stack_a);

/* calc median */
int				get_node_position(t_stack_node *stack, t_stack_node *target);

/* check flags */
int				ft_parse_flags(char **argv, int *strategy, t_bench *bench);

/* check numbers */
void			error(void);
int				ft_is_number(char *str);
long			ft_atol(char *str);
void			ft_check_args(char **argv, int start);
void			ft_check_duplicates(char **argv, int start);

/*chunk sorting helpers*/
int				get_first_match(t_stack_node *stack, int low, int high);
int				get_last_match(t_stack_node *stack, int low, int high);
void			rotate_to_top(t_stack_node **stack_a, int top_pos, int bot_pos, t_bench *bench);
t_stack_node	*find_max_node(t_stack_node *stack);

/* chunk sorting */
int				get_chunk_size(int size, int strategy);
void			push_chunks_b(t_stack_node **stack_a,t_stack_node **stack_b, int chunk, t_bench *bench);
void			sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b, int strategy, t_bench *bench);

/* complex_sort */
void			complex_sort(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* create stack */
int				stack_size(t_stack_node *st);
void			get_rank(t_stack_node *sa, int size);
t_stack_node	*create_stack(char **av, int ac);

/* helpers */
void			error_stack(t_stack_node **a, t_stack_node **b);
void			free_stack(t_stack_node **lst);
void			ft_putstr(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);

/* join args */
char			*join_args(char **argv, int start);

/* main */
int	main(int argc, char **argv);

/* push */
void			pa(t_stack_node **a, t_stack_node **b, t_bench *bench);
void			pb(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* reverse rotate */
void			rra(t_stack_node **a, t_bench *bench);
void			rrb(t_stack_node **b, t_bench *bench);
void			rrr(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* rotate */
void			ra(t_stack_node **a, t_bench *bench);
void			rb(t_stack_node **b, t_bench *bench);
void			rr(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* short input */
void			sort_short(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* simple sort */
void			simple_sort(t_stack_node **a, t_stack_node **b, t_bench *bench);

/* split */
char			**ft_split(char *str, char c);
void			free_split(char **split);

/* swap */
void			sa(t_stack_node **a, t_bench *bench);
void			sb(t_stack_node **b, t_bench *bench);
void			ss(t_stack_node **a, t_stack_node **b, t_bench *bench);

#endif
