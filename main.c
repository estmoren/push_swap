/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:00:00 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/02 16:08:29 by lumacko          ###   ########.fr       */
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
	//1. salir si no hay argumentos
	if (argc < 2)
		return (0);
	//2. Parte de Esther (FILTRO)
	start = ft_parse_flags(argv, &strategy, &bench);

	//3. Validar argumentos y capturar duplicados
	if (argv[start] == NULL) //usuario ha escrito solo flags pero no numeros
		return (0);
	ft_check_args(argv, start);
	ft_check_duplicates(argv, start);

	//4. Parte de Lucy - sabemos que el input esta seguro, vamos a CONSTRUIR
	/*
	stack_a = create_stack(argv, start);
	if (!stack_a)
		error_pareso();
	size = stack_size(stack_a);
	get_rank(stack_a, size);
	*/
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
