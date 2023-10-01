# include "murmurlibc.h"

void	pivot_util1(void *elm, int index, void *data)
{
	(void)index;
	if ((int)(((t_link)(elm))[0]) > *((int *)data))
		*((int *)data) = (int)(((t_link)(elm))[0]);
}

void	pivot_util2(void *elm, int index, void *data)
{
	(void)index;
	if (ft_fabs((*((int *)data) / 2) - *((int *)data + 1)) > ft_fabs((*((int *)data) / 2) - *((int *)data + 2)))
		*((int *)data + 1) = *((int *)data + 2);
	*((int *)data + 2) = (int)(((t_link)(elm))[0]);
}

int	find_pivot(t_stacks stacks)
{
	int	bin[3];

	bin[0] = 0;
	bin[1] = 0;
	bin[2] = 0;
	lp_iter(stacks.stack_a, 0, pivot_util1, bin);
	lp_iter(stacks.stack_a, 0, pivot_util2, bin);
	return (bin[1]);
}