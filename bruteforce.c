#include "push_swap.h"

void		bruteforce(t_llist *first, t_llist *second, int *sorted_arr)
{
	static t_func_bf	*func_bf = NULL;
	t_bf				bf[9];
	int					max;
	int					check;
	int					i;

		// printf("%d %d %d\n", first->tail->value, second->head->value, first->head->value);
	if (func_bf == NULL)
		func_bf = init_func_bf();
	max = get_max(first->head);
	if (get_max(first->head) < second->head->value)
	{
		sort_r(first, second, second->head->value);
	}
	else
	{
		i = 0;
		check = 0;
		while (i < 8)
		{
			bf[i] = base_bf(first, second, func_bf, i);
			if (bf[i].count != -1)
				check = 1;
			i++;
		}
		if (check == 0)
			r(first);
		else
			move_bf(first, second, bf);
		func_bf->min = INT_MAX;
		if (check_sorted(first) == 0)
		{
			exit(0);
		}
	}
}

void		sort_r(t_llist *f_list, t_llist *s_list, int max)
{
	t_node	*node;
	int		r_cnt;
	int		rr_cnt;

	node = f_list->head;
	r_cnt = 0;
	while (!(node->value < node->prev->value
			&& node->prev->value < max))
	{
		rf_(&node, NULL);
		r_cnt++;
	}
	node = f_list->head;
	rr_cnt = 0;
	while (!(node->value < node->prev->value
			&& node->prev->value < max))
	{
		rrf_(&node, NULL);
		rr_cnt++;
	}
	if (!r_cnt & !rr_cnt)
		p(f_list, s_list);
	else if (r_cnt > rr_cnt)
	{
		while (rr_cnt--)
			rr(f_list);
	}
	else
	{
		while (r_cnt--)
			r(f_list);
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
