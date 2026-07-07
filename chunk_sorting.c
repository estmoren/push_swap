/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:00:05 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/07 15:00:35 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (45);
}

void	push_chunks_b(t_stack_node **stack_a, t_stack_node **stack_b, int chunk_size)
{
	int	low_boundary;
	int	high_boundary;

	low_boundary = 0;
	high_boundary = chunk_size -1;
	while (*stack_a)
	{
		if ((*stack_a)->rank >= low_boundary && (*stack_a)->rank <= high_boundary)
		{
			pb(stack_a, stack_b);
			if (stack_size(*stack_b) ==  high_boundary + 1)
			{
				low_boundary += chunk_size;
				high_boundary = low_boundary + (chunk_size - 1);
			}
		}
		else
			ra(stack_a);
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
			max_node = stack; // assigning node to node, not just value
		stack = stack->next;
	}
	return (max_node);
}
void push_back_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*max_node;
	int				position;
	int				b_size;

	while(*stack_b)
	{
		max_node = find_max_node(*stack_b);
		position = get_node_position(*stack_b, max_node);
		b_size = stack_size(*stack_b);
		while (*stack_b != max_node)
		{
			if (position <= (b_size / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}

void	sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	total_size;
	int	chunk_size;

	total_size = stack_size(*stack_a);
	chunk_size = get_chunk_size(total_size);
	push_chunks_b(stack_a, stack_b, chunk_size);
	push_back_a(stack_a, stack_b);
}
