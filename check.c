#include "push_swap.h"

char		*check_arg_num(int argc)
{
	if (argc < 2)
		return ("Too few arguments");
	return (OK);
}

char		*check_duplicate(t_llist *list)
{
	int		i;
	int		j;
	t_node	*base;
	t_node	*comp;

	base = list->head;
	comp = base->next;
	i = 0;
	while (i < list->size)
	{
		j = i;
		comp = base->next;
		while (j < list->size - 1)
		{
			if (base->value == comp->value)
			{
				return ("Duplicate arguments");
			}
			comp = comp->next;
			j++;
		}
		base = base->next;
		i++;
	}
	return (OK);
}

int			check_number()
{
	int		i;

	i = 0;
	while (i < list->size)
	{

	}
}

int			check_sign(char *str)
{

}
