#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // will be deleted
# include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*pre;


}					t_node;

typedef struct		s_head
{
	int				size;
	struct s_node	*next;
}					t_head;

# endif
