#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;

	b = init_list('b');
	if ((a = make_list(argc, argv)) == NULL || !check_duplicate(a))
		print_error("ERROR - There is wrong argument\n");
	print_ab(a, b);
	//solve(a, b);
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
	printf("%s", error);
	//write(1, error, ft_strlen(error));
	exit(0);
}

void			print_ab(t_llist *a, t_llist *b)
{
	printf("a: ");
	for (int i = 0; i < a->size; i++)
	{
		printf("%3d |", a->head->value);
		a->head = a->head->next;
	}
	printf("\n");
	printf("b: ");
	for (int i = 0; i < b->size; i++)
	{
		printf("%3d |", b->head->value);
		b->head = b->head->next;
	}
	printf("\n");
}
