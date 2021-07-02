#include "push_swap.h"

int			*nodes_to_array_back(t_node *node, int size)
{
	int		*array;
	int		i;

	array = ft_calloc(size, sizeof(int));
	i = size - 1
	while (i >= 0)
	{
		array[i] = node->value;
		node = node->next;
		i--;
	}
	return (array);
}

void		add_node(t_arg *arg, char *str)
{
	t_arg	*new_arg;

	new_arg = malloc(sizeof(t_arg));
	new_arg->str = str;
	new_arg->next = NULL;
	if (arg == NULL)
		arg = new_arg;
	else
	{
		while (arg->next)
			arg = arg->next;
		arg->next = new_arg;
	}
}

void		add_node_split(t_llist *list, char *str)
{
	char	**new_str;
	int		i;

	new_str = ft_split(str, ' ');
	i = 0;
	while ((new_str[i]))
		add_node(list, new_str[i++]);
}
