#include "push_swap.h"

int				*lis(t_llist *a, t_llist *b)
{
	t_lis		*lis;
	int			min_value;
	t_node		*node;

	node = a->head;
	lis = malloc(sizeof(t_lis));
	min_value = 0[sort(a)];
	while (1)
	{
		if (min_value == node->value)
			break ;
		node = node->next;
	}
	lis->size = a->size;
	lis->array = calc_lis(nodes_to_array(node, a->size), &lis->size);
	move_lis(a, b, lis, min_value);
}


void		move_lis(t_llist *a, t_llist *b, t_lis *lis, int min_value)
{
	int		i;
	int		list_size;
	int		temp = 0;

	i = 0;
	list_size = a->size;
	print_ab(a, b);
	while (i < list_size)
	{
		if (find_value(a->tail->value, lis) == -1)
			p(b, a);
		else
			rr(a);
		print_ab(a, b);
		i++;
	}
}

void		init_calis(t_calis *calis, int size)
{
	calis->dp = malloc(sizeof(int) * size);
	calis->v = malloc(sizeof(int) * size);
}

int			*calc_lis(int *arr, int *size)
{
	t_calis	calis;
	int		cnt;
	int		i;
	int		pos;

	init_calis(&calis, *size);
	cnt = 0;
	calis.v[0] = arr[1];
	i = 2;
	while (i <= *size)
	{
		if (calis.v[cnt] < arr[i])
		{
			calis.v[++cnt] = arr[i];
			calis.dp[i] = cnt;
		}
		else
		{
			pos = lower_bound(arr, arr[i], cnt);
			calis.v[pos] = arr[i];
			calis.dp[i] = pos;
		}
		i++;
	}
	int LIS_size = cnt;
	res = malloc(sizeof(int) * (LIS_size + 1));
	for (int i = *size; i >= 0; i--)
	{
		if (dp[i] == LIS_size)
		{
			res[LIS_size] = arr[i];
			LIS_size--;
		}
	}
	*size = cnt + 1;
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
	while (end - start > 0)
	{
		mid = (start + end) / 2;
		if (arr[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	return (end);
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
