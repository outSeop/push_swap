#include "push_swap.h"

t_bf		base_bf(t_llist *first, t_llist *second, t_func_bf *func_bf, int kinds)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;

	res.count = 0;
	res.kind = kinds;
	f_node = first->head;
	s_node = second->head;
	while (f_node->prev->value < s_node->value &&
			s_node->value <f_node->value)
	{
		func_bf->func[kinds](&f_node, &s_node);
		res.count += func_bf->incre[kinds];
		if (res.count > func_bf->min)
		{
			res.count = -1;
			break ;
		}
	}
	return (res);
}

void
