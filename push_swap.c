#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;

	if ((a = make_list(argc, argv)) == NULL)
		print_error("ERROR - There is wrong argument\n");
	print_node(a);
	remove_node_back(a);
	print_node(a);
}

t_llist				*make_list(int argc, char *argv[])
{
	t_llist		*list;

	if (argc < 2)
		return (NULL);
	list = malloc(sizeof(t_llist));
	list->head = malloc(sizeof(t_head));
	list->head->next = NULL;
	list->tail = malloc(sizeof(t_tail));
	list->tail->prev = NULL;
	list->size = 0;
	while (list->size < argc - 1)
	{
		add_node(list, argv[list->size + 1]);
		list->size++;
	}
	return (list);
}

void				print_error(char *error)
{
	write(1, error, ft_strlen(error));
	exit(0);
}
