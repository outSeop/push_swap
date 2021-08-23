#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_llist		*a;
	t_llist		*b;
	t_arg		*arg;

	b = init_list('b');
	if (argc < 2)
		print_error("ERROR - Too few argument");
	arg = split_arg(argc, argv);
	if (check_number(arg) == FALSE)
		print_error("ERROR - invalid argument");
	a = make_list(arg);
	if (check_duplicate(a) == FALSE)
		print_error("ERROR - duplicate argument");
	// while (b->head->value != sort(b)[0])
	// 	r(b);
	// while (a->head->value != sort(a)[0])
	// 	r(a);

	while (a->head)
		solve_r(a, b, a->size);
	int tmp = b->size / 2;
	while (tmp--)
		p(a, b);
	while (b->head)
		solve(b, a, b->size);
	lis_hold(a, b, 0);
	// lis_give(b, a, 0);
	int i = 0;
	while (b->size)
	{
		bruteforce(a, b, sort(a));
		i++;
	}
	// lis_hold(a, b, 0);
	// rr(b);
	// p(a, b);
	// while (b->head)
	// 	select_move(a, b);
	printf("ans: %d\n", a->count + b->count);
}

t_llist				*init_list(char name)
{
	t_llist			*list;

	list = malloc(sizeof(t_llist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->count = 0;
	list->sorted = 0;
	init_cnt(list);
	list->name = name;
	return (list);
}

void				init_cnt(t_llist *list)
{
	list->cnt_p = 0;
	list->cnt_r = 0;
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
