#include "push_swap.h"

void			solve(t_llist *a, t_llist *b)
{
	int			*pivots;
	int			i;
	int			c;

	 c = 0;
	pivots = find_pivots(sort(a), a->size);
	printf("!! %d\n", a->size);
	printf("%d\n", pivots[0]);
	i = a->size + 1;
	print_ab(a, b);
	while (i >= 0)
	{
		if (pivots[0] <= a->tail->value)
			p(b, a);
		else
			r(a);
		i--;
		c++;
	print_ab(a, b);
	}
	printf("== %d ==\n", c);
}

int				*find_pivots(int *array, int size)
{
	int			*pivots;

	pivots = malloc(sizeof(int) * 1);
	pivots[0] = array[size / 2];
	return (pivots);
}
