#include "push_swap.h"

void			d_ss(t_llist *first, t_llist *second)
{
	swap(first);
	swap(second);
	first->size++;
	printf("ss\n");
}

void			d_rr(t_llist *first, t_llist *second)
{
	rotate(first);
	rotate(second);
	first->size++;
	printf("rr\n");
}

void			d_rrr(t_llist *first, t_llist *second)
{
	r_rotate(first);
	r_rotate(second);
	first->size++;
	printf("rrr\n");
}
