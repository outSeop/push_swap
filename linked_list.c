#include "push_swap.h"

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
		list->tail = new_node;
	}
	list->size++;
}

void		remove_node_back(t_llist *list)
{
	t_node	*removed_node;

	list->tail->prev->next = list->head;
	list->head->prev = list->tail->prev;
	list->size--;
}

int			get_top(t_head *head)
{

}

void		print_node(t_llist *list)
{
	t_node	*node;
	int		i;

	printf("== ==\n");
	printf("%d %d\n", list->head->value, list->tail->value);
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
