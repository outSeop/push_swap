#include "push_swap.h"

void			solve(t_llist *a, t_llist *b)
{
	int			*pivots;
	int			tmp;
	int			i;
	int			min_value;

	lis(a);
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

int				*lis(t_llist *list)
{
	int			i;
	int			*dp;
	t_node		*node;
	int			*before_index;

	before_index = malloc(sizeof(int) * list->size);
	before_index[0] = -1;
	dp = malloc(sizeof(int) * list->size);
	node = list->head;
	dp[0] = 0[sort(list)];
	while (1)
	{
		if (dp[0] == node->value)
			break ;
		node = node->next;
	}
	i = 0;
	while (i < list->size)
	{

	}
	return (dp);
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
