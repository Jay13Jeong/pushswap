#include "push_swap.h"

void	rtna(t_v *v)
{
	int		data;
	int		asize;

	data = lst_idx(v->a, v->target);
	asize = ft_lstsize(v->a);
	if (v->target >= asize / 2)
		while (lst_idx(v->a, ft_lstsize(v->a) - 1) != data)
			order("ra", v);
	while (lst_idx(v->a, ft_lstsize(v->a) - 1) != data)
		order("rra", v);
}

void	rtnb(int target, t_v *v)
{
	int		data;
	int		bsize;

	data = lst_idx(v->b, target);
	pop(&v->d, data);
	bsize = ft_lstsize(v->b);
	if (target >= bsize / 2)
		while (lst_idx(v->b, ft_lstsize(v->b) - 1) != data)
			order("rb", v);
	while (lst_idx(v->b, ft_lstsize(v->b) - 1) != data)
	{
		if (v->rrr > 0)
		{
			v->rrr -= 1;
			order("rrr", v);
		}
		else
			order("rrb", v);
	}
	while (v->rrr > 0)
	{
		v->rrr -= 1;
		order("rra", v);
	}
}

void	inserta(t_v *v)
{
	int		i;

	i = ft_lstsize(v->b);
	while (i-- > 0)
	{
		if (ft_lstsize(v->b) - 1 == v->border)
			break ;
		order("pa", v);
	}
}

int	check_abottom(t_v *v)
{
	if (!check_lst(v->a))
		return (0);
	inserta(v);
	return (1);
}

void	print_error(void *e)
{
	e = NULL;
	write(1, "Error\n", 6);
	exit(0);
}
