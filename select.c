#include "push_swap.h"

void			select_move(t_llist *a, t_llist *b)
{
	if (b->head && b->head->value > b->head->next->value)
		s(b);
	if (a->head->value < b->head->value &&  b->head->value < a->head->next->value)
	{
		r(a);
		p(a, b);
	}
	else
		r(a);
}

void			find_naer(t_llist *list, int value)
{
	int			search_r;
	int			search_rr;
	int			i;
	t_node		*node;

	node = list->head;
	i = 0;
	search_r = 0;
	search_rr = 0;
	while (node->value != value)
	{
		search_r++;
		node = node->next;
	}
	while (node->value != value)
	{
		search_rr++;
		node = node->prev;
	}
	if (search_r < search_rr)
	{
		while (--search_r)
			r(list);
	}
	else
	{
		while (--search_rr)
			rr(list);
	}
}

