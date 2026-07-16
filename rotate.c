/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:57:46 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/16 16:46:39 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ra(t_stack_node **a, t_bench *bench)
{
	ft_rotate(a);
	counting_bench(bench, "ra");
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, t_bench *bench)
{
	ft_rotate(b);
	counting_bench(bench, "rb");
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	ft_rotate(a);
	ft_rotate(b);
	counting_bench(bench, "rr");
	write(1, "rr\n", 3);
}
