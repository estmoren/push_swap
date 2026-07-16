/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/16 10:52:16 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void		execute_sort(t_stack_node **a, t_stack_node **b,
		int strategy, t_bench *bench)
{
	if (is_sorted(*a))
		return ;
	if (strategy == ADAPTIVE)
		adaptive_sort(a, b, strategy, bench);
	else if (strategy == COMPLEX)
    {
        set_bench(bench, "Complex", "O(n log n)");
		complex_sort(a, b, bench);
    }
	else if (strategy == SIMPLE)
    {
        set_bench(bench, "Simple", "O(n^2)");
        sort_chunks(a, b, strategy, bench);
    }
    else
    {
        set_bench(bench, "Medium", "O(n*sqrt(n))");
        sort_chunks(a, b, strategy, bench);
    }
}

static t_stack_node		*prepare_stack(char **argv, int start)
{
	char			*string;
	char			**numbers;
	t_stack_node	*stack_a;

	string = join_args(argv, start);
	if (!string)
		return (NULL);
	numbers = ft_split(string, ' ');
	free(string);
	if (!numbers)
		return (NULL);
	if (ft_check_args(numbers,0) || ft_check_duplicates(numbers, 0))
    {
        free_split(numbers);
        error();
    }
	stack_a = create_stack(numbers, 0);
	free_split(numbers);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	t_bench			bench;
	int				strategy;
	int				start_index;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	start_index = ft_parse_flags(argv, &strategy, &bench);
	if (argv[start_index] == NULL)
		return (0);
	stack_a = prepare_stack(argv, start_index);
	if (!stack_a)
		error();
	get_rank(stack_a, stack_size(stack_a));
	bench.disorder = calc_disorder(stack_a);
	execute_sort(&stack_a, &stack_b, strategy, &bench);
	bench_results(&bench);
	free_stack(&stack_a);
	return (free_stack(&stack_b), 0);
}
