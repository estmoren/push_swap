#include "push_swap.h"

static	void	ft_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_stack_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
