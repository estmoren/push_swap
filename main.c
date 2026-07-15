/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/15 17:20:57 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    is_sorted(t_stack_node *stack)
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

static void    execute_sort(t_stack_node **a, t_stack_node **b,
        int strategy, t_bench *bench)
{
    if (is_sorted(*a))
        return ;
    if (strategy == ADAPTIVE)
        adaptive_sort(a, b, strategy, bench);
    else if (strategy == COMPLEX)
        complex_sort(a, b, bench);
    else
        sort_chunks(a, b, strategy, bench);
}

int    main(int argc, char **argv)
{
    t_stack_node    *stack_a;
    t_stack_node    *stack_b;
    t_bench            bench;
    int                strategy;
    int                start_index;

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
    get_rank(stack_a, stack_size(stack_a));
    bench.disorder = calc_disorder(stack_a);
    execute_sort(&stack_a, &stack_b, strategy, &bench);
    bench_results(&bench);
	free_stack(&stack_a);
    return (free_stack(&stack_b), 0);
}
