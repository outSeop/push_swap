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
				return (FALSE);
			comp = comp->next;
			j++;
		}
		base = base->next;
		i++;
	}
	return (TRUE);
}

int			check_number(t_arg *arg)
{
	char	*str;
	int		i;

	while (arg)
	{
		str = arg->str;
		if (check_sign(str) == FALSE)
			return (FALSE);
		i = 1;
		while (str[i])
		{
			if (ft_isdigit(str[i]) == FALSE)
				return (FALSE);
			i++;
		}
		arg = arg->next;
	}
	return (TRUE);
}

int			check_sign(char *str)
{
	if (str[0] != '-' && str[0] != '+' && !ft_isdigit(str[0]))
		return (FALSE);
	return (TRUE);
}
