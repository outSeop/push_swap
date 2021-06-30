#include "push_swap.h"

void		swap(t_llist *list)
{
	int		tmp;

	if (list->size < 2)
		return ;
	else
	{
		tmp = list->head->next->value;
		list->head->next->value = list->head->value;
		list->head->value = tmp;
	}
}

void		push(t_llist *first, t_llist *second)
{
	int		tmp;

	if (second->head == NULL)
		return ;
	add_node(first, pop(second));
}

void		rotate(t_llist *list)
{
	if (list->head == NULL)
		return ;
	list->head = list->head->next;
	list->tail = list->tail->next;
}

void		r_rotate(t_llist *list)
{
	if (list->head == NULL)
		return ;
	list->head = list->head->prev;
	list->tail = list->tail->prev;
}
