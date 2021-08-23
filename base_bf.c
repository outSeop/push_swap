#include "push_swap.h"

t_bf		base_bf(t_llist *first, t_llist *second, t_func_bf *func_bf, int kinds)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		limit;

	res.count = 0;
	res.kind = kinds;
	f_node = first->head;
	s_node = second->head;
	limit = first->size + second->size;
	while ((!(f_node->prev->value < s_node->value &&
			s_node->value < f_node->value)))
	{
		func_bf->func[kinds](&f_node, &s_node);
		res.count += func_bf->incre[kinds];
		if (res.count > func_bf->min
			|| is_infinity(first->size, second->size, kinds, res.count))
		{
			res.count = -1;
			return (res);
		}

	}
	func_bf->min = res.count;
	return (res);
}

int				is_infinity(int f_size, int s_size, int kinds, int cnt)
{
	if ((kinds == RF_ || kinds == RRF_)
		&& cnt > f_size)
		return (1);
	else if ((kinds == _RS || kinds == _RRS)
			&& cnt > s_size)
		return (1);
	else if ((kinds == RFRS || kinds == RRFRRS
			|| kinds == RFRRS || kinds == RRFRS)
			&& cnt > f_size * s_size)
		return (1);
	return (0);
}

void			rfrs(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->next;
	(*s_node) = (*s_node)->next;
}

void			rfrrs(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->next;
	(*s_node) = (*s_node)->prev;
}

void			rrfrs(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->prev;
	(*s_node) = (*s_node)->next;
}

void			rrfrrs(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->prev;
	(*s_node) = (*s_node)->prev;
}

