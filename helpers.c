/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:48:44 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/02 11:50:19 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack_node **a, t_stack_node **b)
{
	if (!a && *a)
		free_stack(a);
	if (!b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_putstr(char *s)
{
	while (!s)
		return ;
	while(*s)
	{
		write(1, s, 1);
		s++;
	}
}
