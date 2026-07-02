#include "push_swap.h"

static int	ft_is_number(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static	long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX)
			return (nb * sign);
		i++;
	}
	return (nb * sign);
}

void	ft_check_args(char **argv, int start)
{
	int		i;
	long	nb;

	i = start;
	while (argv[i] != NULL)
	{
		if (ft_is_number(argv[i]) == 0)
			error();
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error();
		i++;
	}
}

void	ft_check_duplicates(char **argv, int start)
{
	int	i;
	int	j;

	i = start;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				error();
			j++;
		}
		i++;
	}
}
