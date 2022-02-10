#include "push_swap.h"

void	order(char *str, t_v *v)
{
	if (!ft_strncmp("rrr", str, -1))
		rrr(v);
	else if (!ft_strncmp("rra", str, -1))
		rev_rotation(&v->a);
	else if (!ft_strncmp("rrb", str, -1))
		rev_rotation(&v->b);
	else if (!ft_strncmp("ra", str, -1))
		rotation(&v->a);
	else if (!ft_strncmp("rb", str, -1))
		rotation(&v->b);
	else if (!ft_strncmp("pa", str, -1))
		pushpop(&v->b, &v->a);
	else if (!ft_strncmp("pb", str, -1))
		pushpop(&v->a, &v->b);
	else if (!ft_strncmp("sa", str, -1))
		sa(v->a);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	v->cnt++;
}

void	init_struct(t_v *v)
{
	v->cnt = 0;
	v->piece = 11;
	if (v->ssize < 500)
		v->piece = 5;
	else if (v->ssize < 85)
		v->piece = 1;
	v->part = v->piece;
	if (v->ssize < v->piece)
		v->part = 1;
	init_ab(v);
	sort(v->stack, v->ssize);
	init_c(v);
	v->std = ft_lstsize(v->a) / v->piece;
	v->part_curr = 0;
	v->border = -1;
}

void	assemble_parts(t_v *v)
{
	v->rrr = 0;
	while (ft_lstsize(v->b) > 0)
	{
		if (v->border > -1)
			init_d(v, v->border + 1, ft_lstsize(v->b), v->b);
		else
			init_d(v, 0, ft_lstsize(v->b), v->b);
		part_sort_and_pa(v);
		v->border -= v->std;
	}
	while (v->rrr-- > 0)
		order("rra", v);
}

void	push_swap(t_v *v)
{
	init_struct(v);
	make_parts_to_b(v);
	check_ab(v);
	assemble_parts(v);
	check_ab(v);
}

int	main(int argc, char **argv)
{
	char	*abc;
	t_v		v;

	if (argc < 2)
		exit(0);
	abc = malloc(1);
	if (abc == NULL)
		print_error(0);
	abc[0] = '\0';
	abc = join_all(argc, argv, abc);
	if (abc == NULL)
		print_error(0);
	v.stack = make_stack(abc, &v.ssize);
	if (v.stack == NULL)
		print_error(0);
	if (!condition_check(v.stack, v.stack))
		print_error(0);
	push_swap(&v);
	return (0);
}
