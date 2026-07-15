/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:00:05 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/15 17:09:23 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	ft_sqrt(double n)
{
	double	x;
	double	prev;

	if (n <= 0)
		return (0);
	x = n;
	prev = 0;
	while (x != prev)
	{
		prev = x;
		x = 0.5 * (x + n / x);
	}
	return (x);
}

int	get_chunk_size(int size, int strategy)
{
	int	chunk;

	if (strategy == SIMPLE)
		return (2);
	if (strategy == MEDIUM)
		return (18);
	if (strategy == COMPLEX)
		return (45);
	chunk = (int)(1.7 * ft_sqrt((double)size) + 0.5);
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

void	push_chunks_b(t_stack_node **stack_a, t_stack_node **stack_b, int chunk, t_bench *bench)
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
		rotate_to_top(stack_a, top, get_last_match(*stack_a, low, high), bench);
		pb(stack_a, stack_b, bench);
		pushed++;
		if ( pushed == chunk)
		{
			low += chunk;
			high = low + (chunk - 1);
			pushed = 0;
		}
	}
}
static void	push_back_a(t_stack_node **stack_a, t_stack_node **stack_b, t_bench *bench)
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
				rb(stack_b, bench);
			else
				rrb(stack_b, bench);
		}
		pa(stack_a, stack_b, bench);
	}
}
void	sort_chunks(t_stack_node **stack_a, t_stack_node **stack_b, int strategy, t_bench *bench)
{
	int	total_size;
	int	chunk_size;

	total_size = stack_size(*stack_a);
	chunk_size = get_chunk_size(total_size, strategy);
	push_chunks_b(stack_a, stack_b, chunk_size, bench);
	push_back_a(stack_a, stack_b, bench);
}

