#include "push_swap.h"

int				*sort(t_llist *list)
{
	int			*array;
	int			i;
	int			j;
	int			tmp;

	array = list_to_array(list);
	i = 0;
	while (i < list->size)
	{
		j = i;
		while (j < list->size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int				*list_to_array_llist(t_llist *list)
{
	int			i;
	int			*array;
	t_node		*node;

	array = malloc(sizeof(int) * list->size);
	node = list->head;
	i = 0;
	while (i < list->size)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char			**list_to_array_arg(t_arg *arg)
{
	int			i;
	t_arg		*head;
	char		**array;

	head = arg;
	i = 0;
	while (arg)
	{
		i++;
		arg = arg->next;
	}
	array = malloc(sizeof(char*) * i);
	arg = head;
	i = 0;
	while (arg)
	{
		array[i] = arg->str;
		i++;
		arg = arg->next;
	}
	array[i] = NULL;
	return (array);
}
