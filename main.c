/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/02 11:33:10 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	strategy;
	int	bench;
	int	start;

	if (argc < 2)
		return (0);
	start = ft_parse_flags(argv, &strategy, &bench);
	ft_check_args(argv, start);
	ft_check_duplicates(argv, start);
	/*
	//check for input
	sa = create_stack(ac, av);
	sb = NULL;
	size = stack_size(sa);
	get_rank(sa, size);
	stack_size(sa);
	push_swap(&sa, &sb, size);
	*/
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
