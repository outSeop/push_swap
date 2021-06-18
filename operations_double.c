#include "push_swap.h"

void			swap_both(t_llist *a, t_llist *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss", 2);
}

void			rotate_both(t_llist *a, t_llist *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr", 2);
}

void			r_rotate_both(t_llist *a, t_llist *b)
{
	r_rotate(a. 0);
	r_rotate(b, 0);
	write(1, "rrr", 3);
}
