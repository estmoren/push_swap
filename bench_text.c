/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:50:32 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/16 15:01:42 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	item(char *name, int value, char *sep)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(value, 2);
	ft_putstr_fd(sep, 2);
}
static void	bench_steps(t_bench *bench)
{
	ft_putstr_fd("[bench] ", 2);
	item("sa", bench->sa, "     ");
	item("sb", bench->sb, "     ");
	item("ss", bench->ss, "     ");
	item("pa", bench->pa, "     ");
	item("pb", bench->pb, "\n");
	ft_putstr_fd("[bench] ", 2);
	item("ra", bench->ra, "     ");
	item("rb", bench->rb, "     ");
	item("rr", bench->rr, "     ");
	item("rra", bench->rra, "     ");
	item("rrb", bench->rrb, "     ");
	item("rrr", bench->rrr, "\n");
}
static void	bench_disorder(t_bench *bench)
{
	int	whole;
	int	decimals;

	whole = (int)(bench->disorder * 100);
	decimals = (int)(bench->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putstr_fd(".", 2);
	if (decimals < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

static void	bench_strategy(t_bench *bench)
{
	if (!bench->strategy)
		return ;
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench->strategy, 2);
	if (bench->complexity)
	{
		ft_putstr_fd(" / ", 2);
		ft_putstr_fd(bench->complexity, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	bench_results(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	bench_disorder(bench);
	bench_strategy(bench);
	item("[bench] total_operations: ", bench->total, "\n");
	bench_steps(bench);
}
