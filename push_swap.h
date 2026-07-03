

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


int				stack_size(t_stack_node *st);
t_stack_node	*create_stack(char **argv, int start);
void			get_rank(t_stack_node *sa, int size);
float			calc_disorder(t_stack_node *stack_a);

int				ft_parse_flags(char **argv, int *strategy, int *bench);
void			ft_check_args(char **argv, int start);
void			ft_check_duplicates(char **argv, int start);


void			ft_putstr(char *s);
void			free_stack(t_stack_node **lst);
void			error(t_stack_node **a, t_stack_node **b);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
