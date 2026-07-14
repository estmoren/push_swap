/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:26:16 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/14 09:32:04 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a, t_bench *bench)
{
	while ((*a)->rank != 2)
		ra(a, bench);
	ra(a, bench);
	if((*a)->rank == 1)
		sa(a, bench);
}

void	sort_five(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if((*a)->rank == 0 || (*a)->rank == 1)
		{
			pb(b, a, bench);
			i++;
		}
		else
			ra(a, bench);
	}
	while ((*a)->rank != 4)
		ra(a, bench);
	ra(a, bench);
	if ((*a)->rank == 3)
		sa(a, bench);
	while (*b)
	{
		if ((*b)->rank == 0)
			rb(b, bench);
		pa(a,b, bench);
	}
}

void 	sort_short(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if ( size == 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a, bench);
		return ;
	}
	else if (size == 3)
		sort_three(a, bench);
	else
		sort_five(a, b, bench);
}
