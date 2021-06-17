#include "push_swap.h"

int				main(int argc, char *argv[])
{
	t_head		*a;
	t_head		*b;

	if ((a = make_stack(argc, argv)) == NULL)
	{}	// write error


}

t_head				*make_stack(int argc, char *argv)
{
	int			i;
	t_head		*stack;

	if (argc < 2)
		return (NULL);
	stack = malloc(sizeof(t_node));
	stack->next = NULL;
	i = 0;
	while (i < argc)
	{
		add_node(stack, argv[i + 1]);
		i++;
	}
}
