/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_disorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 17:48:34 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/03 12:13:48 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calc_disorder(t_stack_node *stack_a)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;
	int				mistakes;
	int				pairs;

	current_node = stack_a;
	mistakes = 0;
	pairs = 0;
	if (!current_node)
		return (0.0);
	while (current_node->next)
	{
		next_node = current_node->next;
		while (next_node)
		{
			pairs++;
			if (current_node->rank > next_node->rank)
				mistakes++;
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	if (pairs == 0)
		return (0.0);
	return ((double)mistakes / pairs);
}
