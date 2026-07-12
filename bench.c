/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:02:54 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/08 19:48:50 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	creating_bench(t_bench *bench, int enabled)
{
	bench->enabled = enabled;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->strategy = NULL;
	bench->complexity = NULL;
}

void	counting_bench(t_bench *bench, char *op)
{
	if (!bench || !bench->enabled)
		return ;
	bench->total++;
	if (!ft_strncmp(op, "pa", 3))
		bench->pa++;
	else if (!ft_strncmp(op, "pb", 3))
		bench->pb++;
	else if (!ft_strncmp(op, "sa", 3))
		bench->sa++;
	else if (!ft_strncmp(op, "sb", 3))
		bench->sb++;
	else if (!ft_strncmp(op, "ss", 3))
		bench->ss++;
	else if (!ft_strncmp(op, "ra", 3))
		bench->ra++;
	else if (!ft_strncmp(op, "rb", 3))
		bench->rb++;
	else if (!ft_strncmp(op, "rr", 3))
		bench->rr++;
	else if (!ft_strncmp(op, "rra", 4))
		bench->rra++;
	else if (!ft_strncmp(op, "rrb", 4))
		bench->rrb++;
	else if (!ft_strncmp(op, "rrr", 4))
		bench->rrr++;
}

void	bench_setup(t_bench *bench, char **argv)
{
	creating_bench(bench, has_bench(argv));
}
