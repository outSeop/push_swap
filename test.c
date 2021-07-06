#include "push_swap.h"

void			a_to_b(t_llist *a, t_llist *b, int size)
{
	int			pivot;
	int			i;

	if (size <= 1)
		return ;
	init_cnt(a);
	init_cnt(b);
	pivot = find_pivots(sort(a), size)[0];
	i = 0;
	while (i < size)
	{
		if (a->head->value < pivot)
			r(a);
		else
			p(b, a);
		i++;
	}
	i = -1;
	while (++i < a->cnt_r)
		rr(a);
	a_to_b(a, b, a->cnt_r);
}

void			a_to_b_r(t_llist *a, t_llist *b, int size)
{
	int			pivot;
	int			i;

	if (size <= 1)
		return ;
	init_cnt(a);
	init_cnt(b);
	pivot = find_pivots(sort(a), size)[0];
	i = 0;
	while (i < size)
	{
		if (a->head->value >= pivot)
			r(a);
		else
		{
			p(b, a);
			r(b);
		}
		i++;
	}
	i = -1;
	while (++i < a->cnt_r)
		rr(a);
	a_to_b(a, b, a->cnt_r);
}

void			b_to_a(t_llist *a, t_llist *b, int size)
{
	int			pivot;
	int			i;

	if (size <= 1)
	{
		p(a, b);
		return ;
	}
	init_cnt(a);
	init_cnt(b);
	pivot = find_pivots(sort(b), size)[0];
	i = 0;
	while (i < size)
	{
		if (b->head->value > pivot)
			r(b);
		else
			p(a, b);
		i++;
	}
	i = -1;
	while (++i < a->cnt_r)
		rr(b);
}
