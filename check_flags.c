/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 11:37:58 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/14 09:18:44 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_flag(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	return (0);
}

static int	ft_get_strategy(char *arg)
{
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (COMPLEX);
	return (-1);
}

int	ft_parse_flags(char **argv, int *strategy, t_bench *bench)
{
	int	count;
	int	code;

	creating_bench(bench, 0);
	*strategy = ADAPTIVE;
	count = 1;
	if (is_bench(argv[1]))
	{
		bench->enabled = 1;
		count = 2;
	}
	if (argv[count] == NULL)
		return (count);
	code = ft_get_strategy(argv[count]);
	if (code != -1)
	{
		*strategy = code;
		count++;
	}
	else if (ft_is_flag(argv[count]))
		error_parseo();
	return (count);
}

