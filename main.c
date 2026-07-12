/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/09 17:22:21 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				strategy;
	int				bench;
	int				start_index;
	int				size;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	start_index = ft_parse_flags(argv, &strategy, &bench);
	if (argv[start_index] == NULL)
		return (0);
	ft_check_args(argv, start_index);
	ft_check_duplicates(argv, start_index);
	stack_a = create_stack(argv, start_index);
	if (!stack_a)
		error_parseo();
	size = stack_size(stack_a);
	get_rank(stack_a, size);
	sort_chunks(&stack_a, &stack_b, strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
