#include "push_swap.h"

int	sort3data(t_v *v)
{
	int		asize;

	asize = ft_lstsize(v->a);
	if (asize <= 3)
	{
		if (check_abottom(v))
			return (1);
		while (lst_idx(v->a, 0) != lstmax(v->a))
			order("ra", v);
		if (check_abottom(v))
			return (1);
		order("sa", v);
		if (check_abottom(v))
			return (1);
	}
	return (0);
}

void	select_sort(t_v *v)
{
	int		asize;
	int		sml;

	asize = ft_lstsize(v->a);
	sml = lstmin(v->a);
	if (lst_location(v->a, sml) >= asize / 2)
	{
		while (lst_idx(v->a, ft_lstsize(v->a) - 1) != sml)
			order("ra", v);
	}
	else
		while (lst_idx(v->a, ft_lstsize(v->a) - 1) != sml)
			order("rra", v);
}

int	process_last_part(t_v *v)
{
	if (ft_lstsize(v->b) > 0)
		v->border = ft_lstsize(v->b) - 1;
	while (1)
	{
		if (sort3data(v))
			break ;
		select_sort(v);
		if (check_abottom(v))
			break ;
		order("pb", v);
	}
	v->border -= v->std;
	return (1);
}

void	find_parts(t_v *v)
{
	int		i;

	v->target = 0;
	v->move = 0;
	i = -1;
	while (++i < ft_lstsize(v->a))
	{
		if (lst_location(v->d, lst_idx(v->a, ft_lstsize(v->a) - 1 - i)) != -1)
		{
			v->target = ft_lstsize(v->a) - 1 - i;
			v->move = i;
			break ;
		}
	}
	i = -1;
	while (++i < ft_lstsize(v->a))
	{
		if (lst_location(v->d, lst_idx(v->a, i)) != -1)
		{
			if (i + 1 < v->move)
				v->target = i;
			break ;
		}
	}
}

void	make_parts_to_b(t_v *v)
{
	int		i;
	int		j;

	i = 0;
	while (++i < v->part + 1)
	{
		if (i == v->part && process_last_part(v))
			break ;
		init_d(v, v->part_curr, v->part_curr + v->std, v->c);
		j = ft_lstsize(v->d);
		while (j-- > 0)
		{
			find_parts(v);
			check_ab(v);
			rtna(v);
			order("pb", v);
		}
		ft_lstclear(&v->d, dummy);
		v->part_curr += v->std;
	}
}
