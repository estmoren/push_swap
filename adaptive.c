/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:33:00 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/14 09:37:42 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack_node **a, t_stack_node **b, int strategy,
		t_bench *bench)
{
	double	ratio;

	if (stack_size(*a) <= 5)
	{
		set_bench(bench, "Adaptive -> Simple", "O(1)");
		sort_short(a, b, bench);
		return ;
	}
	ratio = calc_disorder(*a);
	if (ratio < 0.5)
	{
		set_bench(bench, "Adaptive -> Medium", "O(n*sqrt(n))");
		sort_chunks(a, b, strategy, bench);
	}
	else
	{
		set_bench(bench, "Adaptive -> Complex", "O(n log n)");
		complex_sort(a, b, bench);
	}
}
