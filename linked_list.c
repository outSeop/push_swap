#include "push_swap.h"

void		add_node(t_head *head, int value)
{
	t_node	*node;
	int		i;

	i = 0;
	node = malloc(sizeof(t_node));
	node->value = ft_atoi(value);
	while (head->next)
		head = head->next;
	head->next = node;
}

void		remove_node(t_head *head)
{

}

int			get_top(t_head *head)
{

}
