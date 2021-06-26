#include "push_swap.h"

void			s(t_llist *first)
{
	swap(first);
	printf("s%c\n", first->name);
}

void			p(t_llist *first, t_llist *second)
{
	push(first, second);
	printf("p%c\n", first->name);
}

void			r(t_llist *first)
{
	rotate(first);
	printf("r%c\n", first->name);
}

void			rr(t_llist *first)
{
	r_rotate(first);
	printf("rr%c\n", first->name);
}
