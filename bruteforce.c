#include "push_swap.h"

void			bruteforce(t_llist *first, t_llist *second)
{
	t_bflist	*f_bflist;
	t_bflist	*s_bflist;
	t_node		**node;

	f_bflist = init_bflist(first->head);
	s_bflist = init_bflist(second->head);
	bfs(f_bflist, s_bflist);

}

t_bflist		*init_bflist(t_node *node)
{
	t_bflist	*new_bflist;

	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->node = node;
	new_bflist->next = NULL;
	return (new_bflist);
}

t_node		**bfs(t_bflist *f_bflist, t_bflist *s_bflist)
{
	int			i;
	int			j;
	t_func		func;
	t_node		**node;

	node = malloc(sizeof(t_node *) * 2);
	func = make_func();
	while (1)
	{
		if (check_bf(f_bflist, s_bflist))
		{
		}
		i = 0;
		while (i < 3)
		{
			j = 0;
			while (j < 3)
			{
				if (i == 0 && j == 0)
				{
					i++;
					j++;
					continue;
				}
				func.func[i](f_bflist);
				func.func[j](s_bflist);
				j++;
			}
			i++;
		}
		f_bflist = f_bflist->next;
		s_bflist = s_bflist->next;
	}
}

int			check_bf(t_bflist *f_bflist, t_bflist *s_bflist)
{
	// printf("%d %d %d\n", f_bflist->node->prev->value, s_bflist->node->value, f_bflist->node->value);

	if (get_max(f_bflist->node) < s_bflist->node->value)
		return (1);
	if (f_bflist->node->prev->value < s_bflist->node->value &&
		s_bflist->node->value < f_bflist->node->value)
		return (1);
	return (0);
}

void		i_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	// printf("I_\n");
	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = bflist->node;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;
}

void		r_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	// printf("R_\n");
	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = bflist->node->next;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;
}

void		rr_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	// printf("RR_\n");
	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = bflist->node->prev;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;

}

t_func		make_func()
{
	t_func	func;

	func.func[0] = i_;
	func.func[1] = r_;
	func.func[2] = rr_;
	return (func);
}
