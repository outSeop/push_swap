#include "push_swap.h"

int			*nodes_to_array(t_node *node, int size)
{
	int		*array;
	int		i;

	array = malloc(sizeof(int) * (size + 1));
	i = 1;
	while (i < size + 1)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	return (array);
}
