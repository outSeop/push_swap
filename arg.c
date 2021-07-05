#include "push_swap.h"

t_arg				*split_arg(int argc, char *argv[])
{
	t_arg			*arg;
	int				i;

	arg = NULL;
	i = 0;
	while (i < argc - 1)
	{
		if (ft_strchr(argv[i + 1], ' '))
			add_arg_split(&arg, argv[i + 1]);
		else
			add_arg(&arg, argv[i + 1]);
		i++;
	}
	return (arg);
}

void		add_arg(t_arg **arg, char *str)
{
	t_arg	*new_arg;
	t_arg	*head;

	new_arg = malloc(sizeof(t_arg));
	new_arg->next = NULL;
	new_arg->str = str;
	if (*arg == NULL)
		*arg = new_arg;
	else
	{
		head = *arg;
		while ((*arg)->next)
			*arg = (*arg)->next;
		(*arg)->next = new_arg;
		*arg = head;
	}
}

void		add_arg_split(t_arg **arg, char *str)
{
	char	**new_strs;
	int		i;

	new_strs = ft_split(str, ' ');
	while (new_strs[i])
	{
		add_arg(arg, new_strs[i]);
		i++;
	}
}
