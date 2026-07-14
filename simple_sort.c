/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 13:03:58 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/13 22:37:48 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack_node **a)
{
	t_stack_node	*node;
	int				min;

	node = *a;
	min = node->value;
	while (node != NULL)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

static void	min_to_top(t_stack_node **a, t_bench *bench)
{
	int	min;

	min = find_min(a);
	while ((*a)->value != min)
		ra(a, bench);
}

void	simple_sort(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	if (stack_size(*a) <= 1)
		return ;
	while (*a != NULL)
	{
		min_to_top(a, bench);
		pb(a, b, bench);
	}
	while (*b != NULL)
		pa(a, b, bench);
}
