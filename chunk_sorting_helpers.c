/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:22:39 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/16 10:57:30 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_match(t_stack_node *stack, int low, int high)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->rank >= low && stack->rank <= high)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	get_last_match(t_stack_node *stack, int low, int high)
{
	int	pos;
	int	last_match;

	pos = 0;
	last_match = -1;
	while (stack)
	{
		if (stack->rank >= low && stack->rank <= high)
			last_match = pos;
		pos++;
		stack = stack->next;
	}
	return (last_match);
}

void	rotate_to_top(t_stack_node **stack_a, int top_pos, int bot_pos,
		t_bench *bench)
{
	int	a_size;

	a_size = stack_size(*stack_a);
	if (top_pos <= (a_size - bot_pos))
	{
		while (top_pos > 0)
		{
			ra(stack_a, bench);
			top_pos--;
		}
	}
	else
	{
		while (bot_pos < a_size)
		{
			rra(stack_a, bench);
			bot_pos++;
		}
	}
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->rank > max_node->rank)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
