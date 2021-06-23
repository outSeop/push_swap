#include "push_swap.h"

void		swap(t_llist *list, char c)
{
	int		tmp;
	if (list->size < 2)
		return ;
	else
	{
		tmp = list->tail->value;
		list->tail->value = list->tail->prev->value;
		list->tail->prev->value = tmp;
	}
}

void		push(t_llist *first, t_llist *second, char c)
{
	int		tmp;

	if (first == NULL)
		return ;
	add_node(second, first->tail->value);
	remove_node_back(first);
}

void		rotate(t_llist *list, char c)
{
	list->head = list->head->next;
	list->tail = list->tail->next;
}

void		r_rotate(t_llist *list, char c)
{
	list->head = list->head->prev;
	list->tail = list->tail->prev;
}

void		print_operation(char *operation, char *c)
{
	//write(1, operation, ft_strlen(operation));
	//write(1, c, ft_strlen(c));
	//write(1, "\n", 1);
}

void		operation(void (*fp)(t_llist* , t_llist* ), t_llist *a, t_llist *b)
{
	if (a != NULL && b != NULL)
	{
		fp(a, b);
	}
}
