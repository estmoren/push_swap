/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:00:05 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/07 16:48:32 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size, int strategy)
{
	if (strategy == SIMPLE)
		return (2);
	if (strategy == MEDIUM)
		return (18);
	if (strategy == COMPLEX)
		return (45);

	if (size <= 100)
		return (20);
	return (45);
}

void	push_chunks_b(t_stack_node **stack_a, t_stack_node **stack_b, int chunk)
{
	int	low;
	int	high;
	int	top;
	int	pushed;

	low = 0;
	high = chunk - 1;
	pushed = 0;
	while (*stack_a)
	{
		top = get_first_match(*stack_a, low, high);
		rotate_to_top(stack_a, top, get_last_match(*stack_a, low, high));
		pb(stack_a, stack_b);
		pushed++;
		if ( pushed == chunk)
		{
			low += chunk;
			high = low + (chunk - 1);
			pushed = 0;
		}
	}
}
void	push_back_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*max_node;
	int				position;
	int				b_size;

	while (*stack_b)
	{
		max_node = find_max_node(*stack_b);
		b_size = stack_size(*stack_b);
		while (*stack_b != max_node)
		{
			position = get_node_position(*stack_b, max_node);
			if (position <= (b_size / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
void	sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b, int strategy)
{
	int	total_size;
	int	chunk_size;

	total_size = stack_size(*stack_a);
	chunk_size = get_chunk_size(total_size, strategy);
	push_chunks_b(stack_a, stack_b, chunk_size);
	push_back_a(stack_a, stack_b);
}

/*
cc -Wall -Wextra -Werror main.c check_flags.c check_numbers.c create_stack.c helpers.c calc_median.c chunk_sorting.c chunk_sorting_helpers.c push.c rotate.c reverse_rotate.c simple_sort.c swap.c -o push_swap

~/M1/push-swap % ./push_swap --medium 12 5 8 1 14 3 9 6 11 2 15 4 10 7 13


*/
