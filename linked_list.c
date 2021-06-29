#include "push_swap.h"

t_llist				*make_list(int argc, char *argv[])
{
	t_llist			*list;
	int				i;

	if (argc < 2)
		return (NULL);
	list = init_list('a');
	i = 0;
	while (i < argc - 1)
	{
		if (!check_number(argv[i + 1]))
			return (NULL);
		if (strchr(argv[i + 1], ' '))
			add_node_split(list, argv[i + 1]);
		else
			add_node(list, atoi(argv[i + 1]));
		i++;
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
		list->tail = new_node;
	}
	list->size++;
}

void		add_node_split(t_llist *list, char *str)
{
	char	**new_str;
	int		i;

	new_str = ft_split(str, ' ');
	i = 0;
	while ((new_str[i]))
		add_node(list, atoi(new_str[i++]));
}

int			pop(t_llist *list)
{
	int		value;
	t_node	*node;

	node = list->tail;
	value = list->tail->value;
	if (list->size != 1)
	{

		list->tail->prev->next = list->head;
		list->head->prev = list->tail->prev;
		list->tail = list->tail->prev;
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
		printf("%d = %d\n", i, node->value);
		node = node->next;
		i++;
	}
}
