#include "push_swap.h"

void			solve(t_llist *a, t_llist *b)
{
	int			*pivots;

	pivots = find_pivots(sort(a), a->size);
	move_value(a, b, pivots);
}

void			move_value(t_llist *a, t_llist *b, int *pivots)
{
	int			i;

	i = a->size;
	while (i > 0)
	{
		if (pivots[0] >= a->head->value)
			p(b, a);
		else
			r(a);
		i--;
	}
}

int				move_one_value(t_llist *a, t_llist *b, int pivot)
{
	int			i;

	i = 0;
	if (pivot <= a->head->value)
	{
		p(b, a);
		return (1);
	}
	return (0);
}

int				*find_pivots(int *array, int size)
{
	int			*pivots;

	pivots = malloc(sizeof(int) * 1);
	pivots[0] = array[size / 3];
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

