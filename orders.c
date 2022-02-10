#include "push_swap.h"

void	sa(t_list *lst)
{
	char	*data;

	if (!(lst && lst->next))
		return ;
	data = ft_lstlast(lst)->content;
	while (lst && lst->next)
	{
		if (!lst->next->next)
		{	
			lst->next->content = lst->content;
			lst->content = data;
			return ;
		}
		lst = lst->next;
	}
}

void	pushpop(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (t_list *)0;
	temp2 = *a;
	if (!*b)
		*b = ft_lstlast(temp2);
	else
		(ft_lstlast(*b))->next = ft_lstlast(temp2);
	while (temp2)
	{
		if (!temp2->next)
		{
			if (temp)
				temp->next = (t_list *)0;
			else
				*a = (t_list *)0;
			return ;
		}
		temp = temp2;
		temp2 = temp2->next;
	}
}

void	rev_rotation(t_list **lst)
{
	t_list	*temp;

	if (!(*lst && (*lst)->next))
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (t_list *)0;
	ft_lstadd_back(lst, temp);
}

void	rotation(t_list **lst)
{
	t_list	*temp;
	t_list	*lst2;

	if (!(*lst && (*lst)->next))
		return ;
	temp = ft_lstlast(*lst);
	lst2 = *lst;
	while (lst2 && lst2->next)
	{
		if (lst2->next == temp)
		{	
			lst2->next = (t_list *)0;
		}
		lst2 = lst2->next;
	}
	temp->next = *lst;
	*lst = temp;
}

void	rrr(t_v *v)
{
	rev_rotation(&v->a);
	rev_rotation(&v->b);
}
