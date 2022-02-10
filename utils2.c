#include "push_swap.h"

void	dummy(void *contnent)
{
	if (contnent)
		return ;
}

void	check_ab(t_v *v)
{
	int		i;
	int		bsize;

	if (!check_lst(v->a))
		return ;
	bsize = ft_lstsize(v->b);
	if (bsize > 0)
	{
		if (!check_lst_rev(v->b))
			return ;
		i = -1;
		while (++i < bsize)
			order("pa", v);
	}
	ft_lstclear(&v->a, dummy);
	ft_lstclear(&v->b, dummy);
	ft_lstclear(&v->c, dummy);
	ft_lstclear(&v->d, dummy);
	free_stack(v->stack);
	exit(0);
}

int	lst_idx(t_list *lst, int idx)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		if (i++ == idx)
			return (ft_atoi(lst->content));
		lst = lst->next;
	}
	return (0);
}

int	lst_location(t_list *lst, int data)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		if (data == ft_atoi(lst->content))
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
