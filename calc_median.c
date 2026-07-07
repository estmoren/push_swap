/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:59:58 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/07 11:21:58 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_position(t_stack_node *stack, t_stack_node *target)
{
	int position;

	position = 0;
	while (stack_b)
	{
		if (stack == target)
			return (position);
		position++;
		stack = stack->next;
	}
	return (position);
}
