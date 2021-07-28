#include "push_swap.h"

void		bruteforce(t_llist *first, t_llist *second, int *sorted_arr)
{
	t_bf	bf[8];
	int		max;

	max = sorted_arr[first->size - 1];
	if (first->tail->value < second->head->value
		&& second->head->value < first->head->value)
	{
		p(first, second);
	}
	else if (max < second->head->value)
	{
		p(first, second);
	}
	else
	{
		bf[RFRS] = rfrs(first, second);
		bf[RFRRS] = rfrrs(first, second);
		bf[RRFRS] = rrfrs(first, second);
		bf[RRFRRS] = rrfrrs(first, second);
		bf[RF_] = rf_(first, second);
		bf[_RS] = _rs(first, second);
		bf[RRF_] = rrf_(first, second);
		bf[_RRS] = _rrs(first, second);

		move_bf(first, second, bf);
	}

}

// t_bf		rfrs(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RFRS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->next;
// 			s_node = s_node->next;
// 			res.count++;
// 		}
// 	return (res);
// }

// t_bf		rfrrs(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RFRRS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->next;
// 			s_node = s_node->prev;
// 			res.count++;
// 		}
// 	return (res);

// }

// t_bf			rrfrs(t_llist *first, t_llist *second)
// {

// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RRFRS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->prev;
// 			s_node = s_node->next;
// 			res.count++;
// 		}
// 	return (res);
// }

// t_bf			rrfrrs(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RRFRRS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->prev;
// 			s_node = s_node->prev;
// 			res.count++;
// 		}
// 	return (res);
// }

// t_bf			rf_(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RF_;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->next;
// 			res.count++;
// 		}
// 	return (res);

// }

// t_bf			_rs(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = _RS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			s_node = s_node->next;
// 			res.count++;
// 			if (res.count > second->size)
// 			{
// 				res.count = -1;
// 				return (res);
// 			}
// 		}
// 	return (res);

// }

// t_bf			rrf_(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = RRF_;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			f_node = f_node->prev;
// 			res.count++;
// 		}
// 	return (res);

// }

// t_bf			_rrs(t_llist *first, t_llist *second)
// {
// 	t_bf	res;
// 	t_node	*f_node;
// 	t_node	*s_node;

// 	res.count = 0;
// 	res.kind = _RRS;
// 	f_node = first->head;
// 	s_node = second->head;
// 	while (!(f_node->prev->value < s_node->value
// 			&& s_node->value < f_node->value))
// 		{
// 			s_node = s_node->prev;
// 			res.count++;
// 			if (res.count > second->size)
// 			{
// 				res.count = -1;
// 				return (res);
// 			}
// 		}
// 	return (res);

// }
