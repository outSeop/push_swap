#include "push_swap.h"

int			bf_min(t_bf bf[])
{

	t_bf	min;
	int		i;

	min.kind = bf[0].kind;
	min.count = bf[0].count;
	i = 0;
	while (i < 8)
	{
		if (bf[i].count < 0)
		{
			i++;
			continue ;
		}
		if (min.count > bf[i].count)
		{
			min.count = bf[i].count;
			min.kind = bf[i].kind;
		}
		i++;
	}
	return (min.kind);
}

void		move_bf(t_llist *first, t_llist *second, t_bf bf[])
{
	int		min;
	int		i;

	min = bf_min(bf);
	printf("======== %d\n", bf[min].count);
	i = 0;
	if (min == RFRS)
	{
		while (i < bf[min].count)
		{
			d_rr(first, second);
			i++;
		}
	}
	else if (min == RFRRS)
	{
		while (i < bf[min].count)
		{
			r(first);
			rr(second);
			i++;
		}
	}
	else if (min == RRFRS)
	{
		while (i < bf[min].count)
		{
			rr(first);
			r(second);
			i++;
		}

	}
	else if (min == RRFRRS)
	{
		while (i < bf[min].count)
		{
			d_rrr(first, second);
			i++;
		}
	}
	else if (min == RF_)
	{
		while (i < bf[min].count)
		{
			r(first);
			i++;
		}
	}
	else if (min == _RS)
	{
		while (i < bf[min].count)
		{
			r(second);
			i++;
		}
	}
	else if (min == RRF_)
	{
		while (i < bf[min].count)
		{
			rr(first);
			i++;
		}
	}
	else if (min == _RRS)
	{
		while (i < bf[min].count)
		{
			rr(second);
			i++;
		}
	}
}

t_cset			*bfs(t_node *f_node, t_node *s_node, t_cset *pre_cset)
{
	t_cset		*cset;

	if (f_node->prev->value < s_node->value &&
		s_node->value < f_node->value)
	{
		return (pre_cset);
	}
}
