#include "push_swap.h"

static int	count_bits(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n >> 1;
		count = count + 1;
	}
	return (count);
}

void	complex_sort(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;

	size = stack_size(*a);
	max_bits = count_bits(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*a)->rank >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			i = i + 1;
		}
		while (*b != NULL)
			pa(a, b);
		bit = bit + 1;
	}
}