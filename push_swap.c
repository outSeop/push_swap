#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;

	b = init_list('b');
	if ((a = make_list(argc, argv)) == NULL)
		printf("123\n");
		//print_error("ERROR - There is wrong argument\n");
	r_rotate(a, 0);
	// print_node(b);
	print_node(a);
}

t_llist				*make_list(int argc, char *argv[])
{
	t_llist		*list;

	if (argc < 2)
		return (NULL);
	list = init_list('a');
	while (list->size < argc - 1)
		add_node(list, atoi(argv[list->size + 1]));
	return (list);
}

t_llist				*init_list(char name)
{
	t_llist			*list;

	list = malloc(sizeof(t_llist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->name = name;
	return (list);
}

void				print_error(char *error)
{
	//write(1, error, ft_strlen(error));
	exit(0);
}
