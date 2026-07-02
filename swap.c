#include "push_swap.h"

static void	ft_swap(t_stack_node **stack)
{
	int	temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	temp = (*stack)->rank;
	(*stack)->rank = (*stack)->next->rank;
	(*stack)->next->rank = temp;
}

void	sa(t_stack_node **a)
{
	ft_swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	ft_swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	ft_swap(a);
	ft_swap(b);
	write (1, "ss\n", 3);
}
