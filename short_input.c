/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:26:16 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/12 22:27:42 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	while ((*a)->rank != 2)
		ra(a);
	ra(a);
	if((*a)->rank == 1)
		sa(a);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if((*a)->rank == 0 || (*a)->rank == 1)
		{
			pb(b, a);
			i++;
		}
		else
			ra(a);
	}
	while ((*a)->rank != 4)
		ra(a);
	ra(a);
	if ((*a)->rank == 3)
		sa(a);
	while (*b)
	{
		if ((*b)->rank == 0)
			rb(b);
		pa(a,b);
	}
}

void 	sort_short(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if ( size == 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->rank > (*a)->next->rank)
			sa(a);
		return ;
	}
	else if (size == 3)
		sort_three(a);
	else
		sort_five(a, b);
}
