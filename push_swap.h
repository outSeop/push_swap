#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // will be deleted
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"

# define TRUE 1
# define FALSE 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct		s_arg
{
	struct s_arg	*next;
	char			*str;
}					t_arg;

typedef struct		s_calis
{
	int				first;
	int				second;
}					t_calis;

typedef struct		s_lis
{
	int				*array;
	int				size;
}					t_lis;

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
	int				count;
	int				sorted;
	int				cnt_r;
	int				cnt_p;
}					t_llist;

/*
** push_swap.c
*/
t_llist				*init_list(char name);
void				print_error(char *error);
void				init_cnt(t_llist *list);

/*
** linked_list.c
*/
void				add_node(t_llist *list, int value);
t_llist				*make_list(t_arg *arg);
int					pop(t_llist *list);
void				add_node_split(t_llist *list, char *str);
void				append(t_llist *list, int value);

/*
** base_operations.c
*/
void				swap(t_llist *list);
void				push(t_llist *first, t_llist *second);
void				rotate(t_llist *list);
void				r_rotate(t_llist *list);

/*
** operation.c
*/
void				s(t_llist *first);
void				p(t_llist *first, t_llist *second);
void				r(t_llist *first);
void				rr(t_llist *first);

/*
** operation_double.c
*/
void				d_ss(t_llist *first, t_llist *second);
void				d_rr(t_llist *first, t_llist *second);
void				d_rrr(t_llist *first, t_llist *second);


/*
** check.c
*/
int					check_arument(int argc, char *arcv[]);
int					check_duplicate(t_llist *list);
int					check_number(t_arg *arg);
int					check_sign(char *str);

/*
** sort.c
*/
int					*sort(t_llist *list);
int					*list_to_array(t_llist *list);

/*
** solve.c
*/
void				solve(t_llist *a, t_llist *b, int size);
int					*find_pivots(int *array, int size);
void				solve_r(t_llist *a, t_llist *b, int size);
void				move_value(t_llist *a, t_llist *b, int *pivots);
void				move_value_r(t_llist *a, t_llist *b, int *pivots);
int				move_one_value(t_llist *a, t_llist *b, int pivot);

/*
** lis.c
*/
void				lis_give(t_llist *a, t_llist *b, int r);
int					*calc_lis(int *arr, int *size);
int					lower_bound(int *arr, int value, int size);
void		move_lis_give(t_llist *a, t_llist *b, t_lis *lis, int *sorted_arr);
int			find_value(int value, t_lis *lis);
void				lis_hold(t_llist *a, t_llist *b, int r);
void		move_lis_hold(t_llist *a, t_llist *b, t_lis *lis, int *sorted_arr);
void		move_move(t_llist *a, t_llist *b);
int			*calc_lis_r(int *arr, int *size);
int				upper_bound(int *arr, int value, int size);

/*
** select.c
*/
void			select_move(t_llist *a, t_llist *b);
int				find_naer(t_llist *list, int value);
/*
** node.c
*/
int			*nodes_to_array(t_node *node, int size);

/*
** util.c
*/
void		revers_arr(int *arr, int size);

/*
** test.c
*/
void			a_to_b(t_llist *a, t_llist *b, int size);
void			b_to_a(t_llist *a, t_llist *b, int size);
void			f_to_s(t_llist *f, t_llist *s, int size);
void			a_to_b_r(t_llist *a, t_llist *b, int size);
/*
** arg.c
*/
t_arg				*split_arg(int argc, char *argv[]);
void		add_arg(t_arg **arg, char *str);
void		add_arg_split(t_arg **arg, char *str);
/*
** will be deleted
*/
void				print_list(t_llist *list);
void				print_node(t_node *node, int size);
void				print_ab(t_llist *a, t_llist *b);
void				move_value(t_llist *a, t_llist *b, int *pivots);


#endif
