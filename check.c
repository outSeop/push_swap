#include "push_swap.h"

int			check_arument(int argc, char *arcv[])
{
	if (argc < 2)
		return (FALSE);
	return (TRUE);
}

int			check_duplicate(t_llist *list)
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
				return (FALSE);
			}
			comp = comp->next;
			j++;
		}
		base = base->next;
		i++;
	}
	return (TRUE);
}

int			check_number(char *str)
{
	while (*str)
		if ((!ft_isdigit(*str++)) && *str != ' ')
			return (FALSE);
	return (TRUE);
}
