#include "push_swap.h"

void			solve(t_llist *a, t_llist *b)
{
	int			*pivots;
	int			tmp;
	int			i;
	int			min_value;

	lis(a, b);
}

void			move_value(t_llist *a, t_llist *b, int *pivots)
{
	int			i;

	i = a->size;
	while (i > 0)
	{
		if (pivots[0] <= a->tail->value)
			p(b, a);
		else
			rr(a);
		i--;
		print_ab(a, b);
	}
}

int				*find_pivots(int *array, int size)
{
	int			*pivots;

	pivots = malloc(sizeof(int) * 1);
	pivots[0] = array[size / 2];
	return (pivots);
}


int			find_index(int num, int *dp, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		if (num == dp[i])
			break ;
		i++;
	}
	return (i);
}
