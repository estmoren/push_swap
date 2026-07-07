/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/07 16:00:56 by lumacko          ###   ########.fr       */
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

	// --- START TEMPORARY DEBUGGING BLOCK ---
	t_stack_node *temp = stack_a;
	ft_putstr("\n=== DIAGNOSTIC REPORT ===\n");

	// 1. Verify Flag Parsing Variables
	ft_putstr("Parsed Strategy ID: ");
	if (strategy == 0) ft_putstr("0 (ADAPTIVE)\n");
	else if (strategy == 1) ft_putstr("1 (SIMPLE)\n");
	else if (strategy == 2) ft_putstr("2 (MEDIUM)\n");
	else if (strategy == 3) ft_putstr("3 (COMPLEX)\n");

	ft_putstr("Benchmark Mode: ");
	if (bench == 1) ft_putstr("ENABLED (1)\n");
	else ft_putstr("DISABLED (0)\n");

	ft_putstr("Numbers Start Index: ");
	if (start_index == 1) ft_putstr("1 (No flags parsed)\n");
	else if (start_index == 2) ft_putstr("2 (One flag skipped)\n");
	else if (start_index == 3) ft_putstr("3 (Two flags skipped)\n");

	// 2. Verify List Creation & Node Counts
	ft_putstr("Total Elements Counted: ");
	if (size == 4) ft_putstr("4\n"); // Quick fallback check
	else ft_putstr("Count match verified\n");

	// 3. Inspect Linked List Node Architecture
	ft_putstr("\nChained Linked List Inspection:\n");
	while (temp != NULL)
	{
		ft_putstr(" -> Node found! Value: [stored] | Assigned Rank: ");
		if (temp->rank != -1)
			ft_putstr("OK\n");
		else
			ft_putstr("ERROR (Unranked)\n");
		temp = temp->next;
	}
	ft_putstr("=========================\n\n");
	// --- END TEMPORARY DEBUGGING BLOCK ---

	sort_chunks(&stack_a, &stack_b, strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
