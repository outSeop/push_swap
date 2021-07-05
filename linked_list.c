#include "push_swap.h"

t_llist				*make_list(t_arg *arg)
{
	t_llist			*list;
	t_node			*node;

	list = init_list('a');
	list->size = 0;
	while (arg)
	{
		append(list, ft_atoi(arg->str));
		arg = arg->next;
	}
	return (list);
}

void		add_node(t_llist *list, int value)
{
	t_node	*new_node;
	t_node	*node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;

	if (list->head == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
		list->head->next = new_node;
		list->head->prev = new_node;
		list->tail->next = new_node;
		list->tail->prev = new_node;
	}
	else
	{
		new_node->next = list->head;
		list->head->prev = new_node;
		new_node->prev = list->tail;
		list->tail->next = new_node;
		list->head = new_node;
	}
	list->size++;
}

void		append(t_llist *list, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->head->next = node;
		list->head->prev = node;
		list->tail->next = node;
		list->tail->prev = node;
	}
	else
	{
		list->tail->next = node;
		node->prev = list->tail;
		list->head->prev = node;
		node->next = list->head;
		list->tail = node;
	}
	list->size++;
}

int			pop(t_llist *list)
{
	int		value;
	t_node	*node;

	node = list->head;
	value = list->head->value;
	if (list->size != 1)
	{
		list->head->next->prev = list->tail;
		list->tail->next = list->head->next;
		list->head = list->head->next;


		free(node);
	}
	else
		list->tail = NULL;
	list->size--;
	return (value);
}

void		print_list(t_llist *list)
{
	t_node	*node;
	int		i;

	printf("Head: %-3d\nTail: %-3d\n", list->head->value, list->tail->value);
	i = 0;
	node = list->head;
	printf("=== up ===\n");
	while (i < list->size)
	{
		printf("%d = %d\n", i, node->value);
		node = node->next;
		i++;
	}
	node = list->tail;
	i--;
	printf("=== down===\n");
	while (i >= 0)
	{
		printf("%d = %d\n", i, node->value);
		node = node->prev;
		i--;
	}
}

void				print_node(t_node *node, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		printf("%d ", node->value);
		node = node->next;
		i++;
	}
}
