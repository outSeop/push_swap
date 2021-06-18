#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // will be deleted
# include <stdlib.h>
# include "Libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_head
{
	struct s_node	*next;
}					t_head;

typedef struct		s_tail
{
	struct s_node	*prev;
}					t_tail;

typedef struct		s_llist
{
	int				size;
	t_head			*head;
	t_tail			*tail;
}					t_llist;

/*
** push_swap.c
*/
void				print_error(char *error);

/*
** linked_list.c
*/

void				add_node(t_llist *list, char *value);
t_node				*get_last_node(t_node *node);
t_llist				*make_list(int argc, char *argv[]);
void				remove_node_back(t_llist *list);

/*
** will be deleted
*/
void				print_node(t_llist *list);

#endif
