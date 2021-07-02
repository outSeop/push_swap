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

int			check_number(char **str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		if (!check_sign(str[i]))
			return (FALSE);
		j = 1;
		while (c = str[i][j])
		{
			if (!ft_isdigit(c))
				return (FALSE);
			j++;
		}
	}
	return (TRUE);
}

int			check_sign(char *str)
{
	if (str[0] == '-' || str[0] == '+' || ft_isdigit(str[0]))
		return (TRUE);
	return (FALSE);
}
