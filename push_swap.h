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

# define RFRS 4
# define RFRRS 5
# define RRFRS 6
# define RRFRRS 7
# define RF_ 0
# define _RS 1
# define RRF_ 2
# define _RRS 3

typedef struct		s_cset
{
	int				command;
	struct s_cset	*next;
}					t_cset;

typedef struct 		s_chead
{
	int				size;
	t_cset			*head;
}					t_chead;


typedef struct		s_bf
{
	int				kind;
	int				count;
}					t_bf;

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

typedef struct		s_func_bf
{
	int				min;
	void			(*func[8])(t_node **, t_node **);
	int				incre[8];
}					t_func_bf;

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
int				is_infinity(int f_size, int s_size, int kinds, int cnt);
void		sort_r(t_llist *f_list, t_llist *s_list, int max);

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
** bruteforce.c
*/
void		bruteforce(t_llist *first, t_llist *second, int *sorted_arr);
int			comp_max(int f, int s);
void		rfrs(t_node **f_node, t_node **s_node);
void		rfrrs(t_node **f_node, t_node **s_node);
void		rrfrs(t_node **f_node, t_node **s_node);
void		rrfrrs(t_node **f_node, t_node **s_node);
void			rf_(t_node **f_node, t_node **s_node);
void			_rs(t_node **f_node, t_node **s_node);
void			rrf_(t_node **f_node, t_node **s_node);
void			_rrs(t_node **f_node, t_node **s_node);
int			check_sorted(t_llist *list);
t_func_bf		*init_func_bf();
t_bf		base_bf(t_llist *first, t_llist *second, t_func_bf *func_bf, int kinds);

/*
** calc_bf.c
*/
void		move_bf(t_llist *first, t_llist *second, t_bf bf[]);
int			bf_min(t_bf bf[]);
int			get_max(t_node *node);
int			get_min(t_node *node);
t_bf		get_biggest_case(t_llist *first, t_llist *second);
/*
** will be deleted
*/
void				print_list(t_llist *list);
void				print_node(t_node *node, int size);
void				print_ab(t_llist *a, t_llist *b);
void				move_value(t_llist *a, t_llist *b, int *pivots);


#endif
