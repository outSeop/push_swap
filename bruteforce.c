#include "push_swap.h"

void		bruteforce(t_llist *first, t_llist *second, int *sorted_arr)
{
	t_bf	bf[9];
	int		max;

		// printf("%d %d %d\n", first->tail->value, second->head->value, first->head->value);
	max = get_max(first->head);
	if (first->tail->value < second->head->value
		&& second->head->value < first->head->value)
	{
		printf("==\n");
		p(first, second);
	}
	else
	{
		// if (get_comp_max(irst->head) < get_max(second->head))
		// 	bf[8] = get_biggest_case(first, second);
		bf[RFRS] = rfrs(first, second);
		bf[RFRRS] = rfrrs(first, second);
		bf[RRFRS] = rrfrs(first, second);
		bf[RRFRRS] = rrfrrs(first, second);
		bf[RF_] = rf_(first, second);
		bf[_RS] = _rs(first, second);
		bf[RRF_] = rrf_(first, second);
		bf[_RRS] = _rrs(first, second);
		for (int i = 0; i < 9; i++)
			printf("%d ", bf[i].count);
		printf("\n");
		move_bf(first, second, bf);
		if (check_sorted(first) == 0)
			exit(0);
	}
}

int			check_sorted(t_llist *list)
{
	int		i;
	int		min;
	t_node	*node;

	min = get_min(list->head);
	node = list->head;
	while (node->value != min)
		node = node->next;
	i = 0;
	while (i < list->size - 1)
	{
		if (node->value > node->next->value)
		{
		printf("%d %d\n", node->value, node->next->value);
			return (0);
		}
		node = node->next;
		i++;
	}
	return (1);
}

t_bf		get_biggest_case(t_llist *first, t_llist *second)
{
	int		max;
	t_bf	res1;
	t_bf	res2;
	t_node	*f_node;

	res1.count = 0;
	res2.count = 0;
	max = get_max(f_node);
	f_node = first->head;
	while (f_node->value != max)
	{
		res1.count++;
		f_node = f_node->next;
	}
	f_node = first->head;
	while (f_node->value != max)
	{
		res2.count++;
		f_node = f_node->prev;
	}
	res1.kind = RF_;
	res2.kind = RRF_;
	if (res1.count < res2.count)
		return (res1);
	return (res2);


}

int			comp_max(int f, int s)
{
	if (f > s)
		return (f);
	return (s);
}

t_bf		rfrs(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;

	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RFRS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->next;
			s_node = s_node->next;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);
}

t_bf		rfrrs(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RFRRS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->next;
			s_node = s_node->prev;
			res.count++;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);

}

t_bf			rrfrs(t_llist *first, t_llist *second)
{

	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RRFRS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->prev;
			s_node = s_node->next;
			res.count++;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);
}

t_bf			rrfrrs(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RRFRRS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->prev;
			s_node = s_node->prev;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);
}

t_bf			rf_(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RF_;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->next;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);

}

t_bf			_rs(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = _RS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			s_node = s_node->next;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);

}

t_bf			rrf_(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = RRF_;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			f_node = f_node->prev;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);

}

t_bf			_rrs(t_llist *first, t_llist *second)
{
	t_bf	res;
	t_node	*f_node;
	t_node	*s_node;
	int		dead_line;
	dead_line = first->size + second->size;
	res.count = 0;
	res.kind = _RRS;
	f_node = first->head;
	s_node = second->head;
	while (!(f_node->prev->value < s_node->value
			&& s_node->value < f_node->value))
		{
			s_node = s_node->prev;
			res.count++;
			if (res.count > dead_line)
			{
				res.count = -1;
				return (res);
			}
		}
	return (res);

}
