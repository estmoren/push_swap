/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estmoren <estmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:06:45 by estmoren          #+#    #+#             */
/*   Updated: 2026/07/15 18:06:48 by estmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	args_length(char **argv, int start)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = start;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
			j++;
		if (j == 0)
			error_parseo();
		len += j + 1;
		i++;
	}
	return (len);
}

char	*join_args(char **argv, int start)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	result = malloc(sizeof(char) * (args_length(argv, start) + 1));
	if (result == NULL)
		return (NULL);
	k = 0;
	i = start;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
			result[k++] = argv[i][j++];
		result[k++] = ' ';
		i++;
	}
	result[k] = '\0';
	return (result);
}
