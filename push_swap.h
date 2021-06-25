#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // will be deleted
# include <stdlib.h>
# include <string.h>
 # include "Libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_llist
{
	char			name;
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_llist;

/*
** push_swap.c
*/
t_llist				*init_list(char name);
void				print_error(char *error);

/*
** linked_list.c
*/
void				add_node(t_llist *list, int value);
t_node				*get_last_node(t_node *node);
t_llist				*make_list(int argc, char *argv[]);
int					pop(t_llist *list);
void				add_node_split(t_llist *list, char *str);

/*
** operations.c
*/
void				swap(t_llist *list, char c);
void				push(t_llist *first, t_llist *second, char c);
void				rotate(t_llist *list, char c);
void				r_rotate(t_llist *list, char c);

/*
** check.c
*/
int					check_arument(int argc, char *arcv[]);
int					check_duplicate(t_llist *list);
int					check_number(char *str);

/*
** will be deleted
*/
void				print_node(t_llist *list);


#endif
