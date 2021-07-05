#include "push_swap.h"

void		revers_arr(int *arr, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
		i++;
	}
}
