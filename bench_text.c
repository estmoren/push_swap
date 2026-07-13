/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:50:32 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/13 09:10:47 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bench_item(char *name, int value)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd("\n", 2);
}

static void	bench_steps(t_bench *bench)
{
	bench_item("sa", bench->sa);
	bench_item("sb", bench->sb);
	bench_item("ss", bench->ss);
	bench_item("pa", bench->pa);
	bench_item("pb", bench->pb);
	bench_item("ra", bench->ra);
	bench_item("rb", bench->rb);
	bench_item("rr", bench->rr);
	bench_item("rra", bench->rra);
	bench_item("rrb", bench->rrb);
	bench_item("rrr", bench->rrr);
}

static void	bench_percentage(double ratio)
{
	int	whole;
	int	decimals;

	whole = (int)(ratio * 100);
	decimals = (int)(ratio * 10000) % 100;
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

static void	bench_disorder(t_bench *bench)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	bench_percentage(bench->disorder);
}

void	bench_results(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	bench_disorder(bench);
	if (bench->strategy)
	{
		ft_putstr_fd("[bench] strategy: ", 2);
		ft_putstr_fd(bench->strategy, 2);
		ft_putstr_fd("\n", 2);
	}
	if (bench->complexity)
	{
		ft_putstr_fd("[bench] complexity: ", 2);
		ft_putstr_fd(bench->complexity, 2);
		ft_putstr_fd("\n", 2);
	}
	bench_item("operations", bench->total);
	bench_steps(bench);
}
