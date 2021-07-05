#include "push_swap.h"

void			select_move(t_llist *a, t_llist *b)
{
	if (a->head->value < b->head->value)
		p(a, b);
	else
		r(b);
}
