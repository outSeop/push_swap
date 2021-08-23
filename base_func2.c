#include "push_swap.h"

t_func_bf		*init_func_bf()
{
	int			i;
	t_func_bf	*func_bf;

	func_bf = malloc(sizeof(t_func_bf));
	func_bf->func[RF_] = rf_;
	func_bf->func[_RS] = _rs;
	func_bf->func[RRF_] = rrf_;
	func_bf->func[_RRS] = _rrs;
	func_bf->func[RFRS] = rfrs;
	func_bf->func[RFRRS] = rfrrs;
	func_bf->func[RRFRS] = rrfrs;
	func_bf->func[RRFRRS] = rrfrrs;
	func_bf->incre[RF_] = 1;
	func_bf->incre[_RS] = 1;
	func_bf->incre[RRF_] = 1;
	func_bf->incre[_RRS] = 1;
	func_bf->incre[RFRS] = 1;
	func_bf->incre[RFRRS] = 2;
	func_bf->incre[RRFRS] = 2;
	func_bf->incre[RRFRRS] = 1;
	func_bf->min = INT_MAX;
	return (func_bf);
}

void			rf_(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->next;
}

void			_rs(t_node **f_node, t_node **s_node)
{
	(*s_node) = (*s_node)->next;
}

void			rrf_(t_node **f_node, t_node **s_node)
{
	(*f_node) = (*f_node)->prev;
}

void			_rrs(t_node **f_node, t_node **s_node)
{
	(*s_node) = (*s_node)->prev;
}
