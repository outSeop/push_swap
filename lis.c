#include "push_swap.h"

void				lis_give(t_llist *a, t_llist *b, int r)
{
	t_lis		*lis_v;
	int			*sorted_arr;
	t_node		*node;

	init_cnt(a);
	init_cnt(b);
	node = a->head;
	lis_v = malloc(sizeof(t_lis));
	sorted_arr = sort(a);
	while (1)
	{
		if (sorted_arr[0] == node->value)
			break ;
		node = node->next;
	}
	lis_v->size = a->size;
	int *arr = nodes_to_array(node, a->size);
	lis_v->array = calc_lis(arr, &lis_v->size);
	a->sorted = lis_v->size;
	move_lis_give(a, b, lis_v, sorted_arr);
}

void				lis_hold(t_llist *a, t_llist *b, int r)
{
	t_lis		*lis_v;
	int			*sorted_arr;
	t_node		*node;

	init_cnt(a);
	init_cnt(b);
	node = a->head;
	lis_v = malloc(sizeof(t_lis));
	sorted_arr = sort(a);
	while (1)
	{
		if (sorted_arr[0] == node->value)
			break ;
		node = node->next;
	}
	lis_v->size = a->size;
	int *arr = nodes_to_array(node, a->size);
	lis_v->array = calc_lis(arr, &lis_v->size);
	a->sorted = lis_v->size;
	move_lis_hold(a, b, lis_v, sorted_arr);
}

void		move_lis_hold(t_llist *a, t_llist *b, t_lis *lis, int *sorted_arr)
{
	int		i;
	int		list_size;
	int		cnt_pb = 0;
	int		*pivots;

	pivots = find_pivots(sorted_arr, a->size);
	i = 0;
	list_size = a->size;
	while (i < list_size)
	{
		if (find_value(a->head->value, lis) == -1)
		{
			p(b, a);
		}
		else
			r(a);
		i++;
	}
}

void		move_lis_give(t_llist *a, t_llist *b, t_lis *lis, int *sorted_arr)
{
	int		i;
	int		list_size;
	int		cnt_pb = 0;

	i = 0;
	list_size = a->size;
	while (i < list_size)
	{
		if (find_value(a->head->value, lis) == -1)
		{
				r(a);
		}
		else
		{
			p(b, a);
			r(b);
		}
		i++;
	}
}

void		move_move(t_llist *a, t_llist *b)
{
	if (a->head->value > b->head->value)
		p(a, b);
	else
		r(a);
}

int			*calc_lis(int *arr, int *size)
{
	t_calis	*calis;
	int		*res;
	int		p_lis;
	int		p_arr;
	int		*lis;
	int		pos;

	p_lis = 0;
	p_arr = 1;
	lis = malloc(sizeof(int) * *size);
	calis = malloc(sizeof(t_calis) * *size);
	lis[p_lis] = arr[0];
	calis[0].first = 0;
	calis[0].second = arr[0];
	while (p_arr < *size)
	{
		if (lis[p_lis] < arr[p_arr])
		{
			lis[++p_lis] = arr[p_arr];
			calis[p_arr].first = p_lis;
			calis[p_arr].second = arr[p_arr];
		}
		else
		{
			pos = lower_bound(lis, arr[p_arr], p_lis);
			lis[pos - 1] = arr[p_arr];
			calis[p_arr].first = pos - 1;
			calis[p_arr].second = arr[p_arr];
		}
		p_arr++;
	}
	int t = p_lis;
	res = malloc(sizeof(int) * (t + 1));
	for (int i = *size - 1; i >= 0; i--)
	{
		if (calis[i].first == t)
		{
			res[t] = calis[i].second;
			t--;
		}
	}
	*size = p_lis + 1;
	return (res);
}

int				lower_bound(int *arr, int value, int size)
{
	int			start;
	int			end;
	int			mid;

	start = 0;
	end = size;
	mid = size;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (arr[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	return (end + 1);
}

int			find_value(int value, t_lis *lis)
{
	int		i;
	int		start;
	int		end;
	int		mid;

	start = 0;
	end = lis->size - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (value == lis->array[mid])
			return (mid);
		else if (value < lis->array[mid])
			end = mid - 1;
		else if (value > lis->array[mid])
			start = mid + 1;
	}
	return (-1);
}
