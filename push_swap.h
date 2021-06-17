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
	struct s_node	*pre;


}					t_node;

typedef struct		s_head
{
	int				size;
	struct s_node	*next;
}					t_head;

void				add_node(t_head *head, int value);
# endif
