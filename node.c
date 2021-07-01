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
