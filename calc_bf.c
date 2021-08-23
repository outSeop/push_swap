#include "push_swap.h"

int			bf_min(t_bf bf[])
{

	t_bf	min;
	int		i;

	min.count = INT_MAX;
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

int			get_min(t_node *node)
{
	t_node	*start_node;
	int		mix;

	start_node = node;
	mix = node->value;
	node = node->next;
	while (start_node != node)
	{
		if (mix > node->value)
			mix = node->value;
		node = node->next;
	}
	return (mix);
}

int			get_max(t_node *node)
{
	t_node	*start_node;
	int		max;

	start_node = node;
	max = node->value;
	node = node->next;
	while (start_node != node)
	{
		if (max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}
void		move_bf(t_llist *first, t_llist *second, t_bf bf[])
{
	int		min;
	int		i;

	min = bf_min(bf);
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
	p(first, second);
}
