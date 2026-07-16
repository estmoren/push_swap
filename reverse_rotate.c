/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:57:34 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/16 16:47:00 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*prev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	rra(t_stack_node **a, t_bench *bench)
{
	ft_reverse_rotate(a);
	counting_bench(bench, "rra");
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, t_bench *bench)
{
	ft_reverse_rotate(b);
	counting_bench(bench, "rrb");
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	counting_bench(bench, "rrr");
	write(1, "rrr\n", 4);
}
