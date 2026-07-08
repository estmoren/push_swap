/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:48:35 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/08 19:49:35 by lumacko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_bench(char *arg)
{
	if (!arg)
		return (0);
	if (!ft_strncmp(arg, "--bench", 8))
		return (1);
	return (0);
}

int	has_bench(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_bench_arg(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
