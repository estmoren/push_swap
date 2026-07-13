/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:57:20 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/13 10:03:47 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (src == NULL || *src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	pa(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	ft_push(a, b);
	bench_count(bench, "pa");
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	ft_push(b, a);ň
	bench_count(bench, "pb");
	write(1, "pb\n", 3);
}
