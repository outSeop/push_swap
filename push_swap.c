#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;

	b = init_list('b');
	if ((a = make_list(argc, argv)) == NULL)
		printf("123\n");
		//print_error("ERROR - There is wrong argument\n");
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
