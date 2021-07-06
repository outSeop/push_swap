#include "push_swap.h"

void			s(t_llist *first)
{
	if (first->head == NULL)
		return ;
	swap(first);
	first->count++;
	printf("s%c\n", first->name);
}

void			p(t_llist *first, t_llist *second)
{
	if (second->head == NULL)
		return ;
	push(first, second);
	first->cnt_p++;
	first->count++;
	printf("p%c\n", first->name);
}

void			r(t_llist *first)
{
	if (first->head == NULL)
		return ;
	rotate(first);
	first->cnt_r++;
	first->count++;
	printf("r%c\n", first->name);
}

void			rr(t_llist *first)
{
	if (first->head == NULL)
		return ;
	r_rotate(first);
	first->count++;
	printf("rr%c\n", first->name);
}
