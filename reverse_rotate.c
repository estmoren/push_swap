#include "push_swap.h"

static	void ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*prev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	while(prev->next->next != NULL)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	rra(t_stack_node **a)
{
	ft_reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	ft_reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
