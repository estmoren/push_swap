/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:33:00 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/13 09:45:29 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_bench(t_bench *bench, char *strategy,
		char *complexity)
{
	bench->strategy = strategy;
	bench->complexity = complexity;
}
void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	ratio;

	if (stack_size(*a) <= 5)
	{
		sort_short(a, b, bench);
		return ;
	}
	ratio = disorder_ratio(*a);
	if (ratio < 0.2)
		sort_short(a, b, bench);
	else if (ratio < 0.5)
	{
		set_bench(bench, "Adaptive -> Medium", "O(n*sqrt(n))");
		chunk_sort(a, b, bench);
	}
	else
	{
		set_bench(bench, "Adaptive -> Complex", "O(n log n)");
		complex_sort(a, b, bench);
	}
}
