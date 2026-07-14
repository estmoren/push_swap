/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:57:58 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/13 22:29:56 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_stack_node **a, t_bench *bench)
{
	ft_swap(a);
	counting_bench(bench, "sa"); //added
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b, t_bench *bench)
{
	ft_swap(b);
	counting_bench(bench, "sb"); //added
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	counting_bench(bench, "ss"); //added
	write (1, "ss\n", 3);
}
