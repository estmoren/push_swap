#include "push_swap.h"

static void	ft_push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
