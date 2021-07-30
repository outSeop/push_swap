#include "push_swap.h"

void			bruteforce(t_llist *first, t_llist *second)
{
	t_cset		*cset;
	t_bflist	*f_bflist;
	t_bflist	*s_bflist;

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
	new_bflist->cset = NULL;
	return (new_bflist);
}

t_cset			**bfs(t_bflist *f_bflist, t_bflist *s_bflist)
{
	int			i;
	int			j;
	void		(*fp[3])(t_bflist *);
	t_cset		*cset[2];

	while (1)
	{
		if (check_bf(f_bflist, s_bflist))
		{
			cset[0] = f_bflist->cset;
			cset[1] = s_bflist->cset;
			return (cset);
		}
		i = 0;
		while (i < 3)
		{
			while (j < 3)
			{
				fp[i](f_bflist);
				fp[j](s_bflist);
				j++;
			}
			i++;
		}
	}
}

int			check_bf(t_bflist *f_bflist, t_bflist *s_bflist)
{
	if (f_bflist->node->prev < s_bflist->node &&
		s_bflist->node < f_bflist->node)
		return (1);
	return (0);
}

void		i_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = new_bflist->node;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;
	add_cset(&(bflist->cset), I_);
}

void		r_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = new_bflist->node->next;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;
	add_cset(&(bflist->cset), R_);
}

void		rr_(t_bflist *bflist)
{
	t_bflist	*new_bflist;

	new_bflist = malloc(sizeof(t_bflist));
	new_bflist->next = NULL;
	new_bflist->node = new_bflist->node->prev;
	while (bflist->next)
		bflist = bflist->next;
	bflist->next = new_bflist;
	add_cset(&(bflist->cset), RR_);
}

void		add_cset(t_cset **cset, int command)
{
	t_cset	*new_cset;
	t_cset	*start;

	new_cset = malloc(sizeof(t_cset));
	new_cset->command = command;
	new_cset->next = NULL;
	if ((*cset) == NULL)
	{
		(*cset) = new_cset;
		return ;
	}
	start = (*cset);
	while ((*cset)->next)
		(*cset) = (*cset)->next;
	(*cset)->next = new_cset;
	(*cset) = start;
}
