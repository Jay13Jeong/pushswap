#include "push_swap.h"

void	parts_idx_cmp(t_v *v)
{
	int		big;
	int		sml;
	int		b;
	int		s;

	big = lstmax(v->b);
	sml = lstmin(v->d);
	b = lst_location(v->b, big);
	s = lst_location(v->b, sml);
	v->b_d = ft_lstsize(v->b) - (b + 1);
	if (b + 1 - v->rrr < v->b_d)
		v->b_d = b + 1 - v->rrr;
	v->s_d = ft_lstsize(v->b) - (s + 1) + 1;
	if (s + 1 - v->rrr + 1 < v->s_d)
		v->s_d = s + 1 - v->rrr + 1;
	if (v->b_d <= v->s_d)
		rtnb(b, v);
	else
	{
		rtnb(s, v);
		v->rrr2 += 1;
	}
}

void	part_sort_and_pa(t_v *v)
{
	int		b_last;
	int		a_last;

	v->rrr2 = 0;
	while (ft_lstsize(v->d) > 0)
	{
		parts_idx_cmp(v);
		v->rrr = 0;
		check_ab(v);
		if (ft_lstsize(v->a) >= 2)
		{
			b_last = lst_idx(v->b, ft_lstsize(v->b) - 1);
			a_last = lst_idx(v->a, ft_lstsize(v->a) - 1);
			if (b_last > a_last)
				order("ra", v);
		}
		order("pa", v);
	}
	ft_lstclear(&v->d, dummy);
	v->rrr = v->rrr2;
}
