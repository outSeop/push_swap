#include "push_swap.h"

void			f_to_s(t_llist *f, t_llist *s, int size)
{
	int			pivot;
	int			i;
	int			cnt_r;

	if (size <= 1)
		return ;
	pivot = find_pivots(sort(f), f->size)[0];
	cnt_r = 0;
	i = 0;
	while (i < size)
	{
		if (f->head->value > pivot)
		{
			r(f);
			cnt_r++;
		}
		else
		{
			p(s, f);
		}
		i++;
	}
	i = -1;
	while (++i < cnt_r)
		rr(f);
}
