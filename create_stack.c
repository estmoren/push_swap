/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:56:44 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/03 09:48:19 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*new_node(int parsed_number)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = parsed_number;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

static void	add_node_end(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node 	*current_list;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		current_list = *lst;
		while (current_list->next)
			current_list = current_list->next;
		current_list->next = new;
	}
}

int	stack_size(t_stack_node *st)
{
	int				size;
	t_stack_node	*temp;

	size = 0;
	temp = st;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	get_rank(t_stack_node *sa, int size)
{
	t_stack_node	*temp;
	t_stack_node	*max_node;
	long			max_num;
	int				current_size;

	current_size = size;
	while (current_size--)
	{
		temp = sa;
		max_node = NULL;
		max_num = LONG_MIN;
		while (temp)
		{
			if (temp->value > max_num && temp->rank == -1)
			{
				max_num = temp->value; //becomes the number
				max_node = temp; //points to the number
			}
			temp = temp->next;
		}
		if (max_node)
			max_node->rank = size;
	}
}

t_stack_node	*create_stack( char **argv, int argc)
{
	t_stack_node	*sa;
	long int		num;
	int				i;

	sa = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		// aqui entran tus funciones para comprobar el imput
		if (num < INT_MIN || num > INT_MAX)
			error (&sa, NULL);
		add_node_end(&sa, new_node((int)num));
		i++;
	}
	return (sa);
}
