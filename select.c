#include "push_swap.h"

void			select_move(t_llist *a, t_llist *b)
{
	if (b->head->value < b->head->next->value)
		s(b);
	if (a->head->value == sort(a)[0])
		p(a, b);
	if (a->head->value < b->head->value)
		r(a);
	else if (a->head->value > b->head->value && a->tail->value > b->head->value)
		rr(a);
	else
		p(a, b);

}

int				find_naer(t_llist *list, int value)
{
	int			search_r;
	int			search_rr;
	int			i;
	t_node		*node;

	node = list->head;
	i = 0;
	search_r = 0;
	search_rr = 0;
	if (node->value == value)
		return (TRUE);
	while (node->value != value && search_r != list->size)
	{
		search_r++;
		node = node->next;
	}
	if (search_r == list->size)
		return (FALSE);
	node = list->head;
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
	return (TRUE);
}

