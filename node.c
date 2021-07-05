#include "push_swap.h"

int			*nodes_to_array(t_node *node, int size)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	return (array);
}
