/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/03 12:17:08 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int				strategy;
	int				bench;
	int				start;
	int				size;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	// 1. Salir si no hay argumentos
	if (argc < 2)
		return (0);
	stack_b = NULL;
	// 2. Parte Esther: flags
	start = ft_parse_flags(argv, &strategy, &bench);
	// 3. Parte Esther: Validar los argumentos
	if (argv[start] == NULL)
		return (0);
	ft_check_args(argv, start);
	ft_check_duplicates(argv, start);
	// 4. Parte Lucy: Construir nodos y listas
	stack_a = create_stack(argv, start);
	if (!stack_a)
		error_parseo();
	size = stack_size(stack_a);
	get_rank(stack_a, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
