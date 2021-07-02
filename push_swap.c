#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;
	char		**str;

	b = init_list('b');
	if (check_number(str = split_arg(argc, argv) == FALSE);
		return (0);
	make_list(str);
	print_ab(a, b);
	//solve(a, b);
}

char			**split_arg(int argc, char *argv[])
{
	int			i;
	t_arg		*arg;
	t_arg		*head;

	arg = malloc(sizeof(t_arg));
	arg->next = NULL;
	head = arg;
	i = 0;
	while (i < argc - 1)
	{
		if (strchr(argv[i + 1], ' '))
			add_node_split(head, argv[i + 1]);
		else
			add_node(head, argv[i + 1]);
	}
	return (list_to_array_arg(head));
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
