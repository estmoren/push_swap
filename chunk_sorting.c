/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:00:05 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/03 09:17:46 by lumacko          ###   ########.fr       */
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
		if ((*stack_a)->rank >= low_boundary && (*stack_a) <= high_boundary)
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

void push_chunks_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	
}

void	sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	total_size;
	int	chunk_size;

	total_size = stack_size(*stack_a);
	chunk_size = get_chunk_size(total_size);
	//Phase 1: group into chunks and push to B
	push_chunks_b(stack_a, stack_b, chunk_size);
	// Phase 2: Move back to A
	push_back_a(stack_a, stack_b);
}
