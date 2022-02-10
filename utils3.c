#include "push_swap.h"

int	lstmax(t_list *lst)
{
	int		max;
	int		temp;

	max = 1 << 31;
	while (lst != NULL)
	{
		temp = ft_atoi(lst->content);
		if (temp > max)
			max = temp;
		lst = lst->next;
	}
	return (max);
}

int	lstmin(t_list *lst)
{
	int		min;
	int		temp;

	min = ~(1 << 31);
	while (lst)
	{
		temp = ft_atoi(lst->content);
		if (temp < min)
			min = temp;
		lst = lst->next;
	}
	return (min);
}

int	check_lst(t_list *lst)
{
	int		temp;
	int		last;

	last = ~(1 << 31);
	while (lst != NULL)
	{
		temp = ft_atoi(lst->content);
		if (temp > last)
			return (0);
		last = temp;
		lst = lst->next;
	}
	return (1);
}

int	check_lst_rev(t_list *lst)
{
	int		temp;
	int		last;

	last = 1 << 31;
	while (lst != NULL)
	{
		temp = ft_atoi(lst->content);
		if (temp < last)
			return (0);
		last = temp;
		lst = lst->next;
	}
	return (1);
}

void	pop(t_list **lst, int data)
{
	t_list	*temp;
	t_list	*temp2;

	temp = (t_list *)0;
	temp2 = *lst;
	while (temp2)
	{
		if (data == ft_atoi(temp2->content))
		{
			if (temp)
				temp->next = temp2->next;
			else
				*lst = temp2->next;
			free(temp2);
			return ;
		}
		temp = temp2;
		temp2 = temp2->next;
	}
}
