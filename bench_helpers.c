/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:48:35 by lumacko           #+#    #+#             */
/*   Updated: 2026/07/16 16:49:01 by lumacko          ###   ########.fr       */
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
		if (is_bench(argv[i]))
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

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd(l % 10 + '0', fd);
}
