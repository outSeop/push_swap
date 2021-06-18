#include "push_swap.h"

void		add_node(t_llist *list, char *value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = ft_atoi(value);
	new_node->next = NULL;
	if (list->head->next == NULL)
	{
		list->head->next = new_node;
		new_node->next = NULL;
		list->tail->prev = new_node;
		new_node->prev = NULL;
	}
	else
	{
		new_node->prev = list->tail->prev;
		new_node->prev->next = new_node;
		new_node->next = NULL;
		list->tail->prev = new_node;
	}
}

void		remove_node_back(t_llist *list)
{
	t_node	*removed_node;

	removed_node = list->tail->prev;
	removed_node->prev->next = NULL;
	list->tail->prev = removed_node->prev;
	free(removed_node);
}

int			get_top(t_head *head)
{

}

void		print_node(t_llist *list)
{
	t_node	*node;
	int		i;

	i = 0;
	node = list->head->next;
	while (node)
	{
		printf("%d = %d\n", i, node->value);
		node = node->next;
		i++;
	}
	node = list->tail->prev;
	i--;
	while (node)
	{
		printf("%d = %d\n", i, node->value);
		node = node->prev;
		i--;
	}
}
