#include "push_swap.h"

void			a_to_b(t_llist *a, t_llist *b, int size)
{
	int			pivot;
	int			i;
	int			cnt_ra = 0;
	int			cnt_pb = 0;

	if (size == 1)
		return ;
	pivot = find_pivots(sort(a), a->size)[0];
	printf("%d\n", pivot);
	while (i< size)
	{
		if (a->head->value > pivot)
		{
			r(a);
			cnt_ra++;
		}
		else
		{
			p(b, a);
			cnt_pb++;
		}
		i++;
	}
	while (--cnt_ra > 0)
		rr(a);
	a_to_b(a, b, cnt_ra);
	b_to_a(a, b, cnt_pb);

}

void			b_to_a(t_llist *a, t_llist *b, int size)
{
	int			pivot;
	int			i;
	int			cnt_rb = 0;
	int			cnt_pa = 0;

	if (size == 1)
	{
		p(a, b);
		return ;
	}
	pivot = find_pivots(sort(b), b->size)[0];
	while (i < size)
	{
		if (b->head->value > pivot)
		{
			r(b);
			cnt_rb++;
		}
		else
		{
			p(a, b);
			cnt_pa++;
		}
		i++;
	}
	while (--cnt_rb > 0)
		rr(b);
	b_to_a(a, b, cnt_rb);
	a_to_b(a, b, cnt_pa);

}
