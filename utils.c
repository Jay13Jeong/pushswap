#include "push_swap.h"

int	free_stack(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (0);
}

void	sort(char **stack, int size)
{
	int		sml;
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i < size - 1)
	{
		sml = i;
		j = i;
		while (++j < size)
		{
			if (ft_atoi(stack[j]) < ft_atoi(stack[sml]))
				sml = j;
		}
		tmp = stack[i];
		stack[i] = stack[sml];
		stack[sml] = tmp;
	}
}

void	init_ab(t_v *v)
{
	int		i;
	t_list	*temp;

	i = v->ssize;
	while (i-- > 0)
	{
		temp = ft_lstnew(v->stack[i]);
		if (temp == NULL)
		{
			write(1, "Error\n", 6);
			free_stack(v->stack);
			ft_lstclear(&v->a, dummy);
			exit(0);
		}
		ft_lstadd_back(&v->a, temp);
	}
	v->b = (t_list *)0;
}

void	init_c(t_v *v)
{
	int		i;
	t_list	*temp;

	i = -1;
	while (++i < v->ssize)
	{
		temp = ft_lstnew(v->stack[i]);
		if (temp == NULL)
		{
			write(1, "Error\n", 6);
			free_stack(v->stack);
			ft_lstclear(&v->a, dummy);
			ft_lstclear(&v->c, dummy);
			exit(0);
		}
		ft_lstadd_back(&v->c, temp);
	}
}

void	init_d(t_v *v, int start, int end, t_list *lst)
{
	int		i;
	t_list	*temp;

	i = -1;
	while (lst != NULL)
	{
		if (++i >= start && i < end)
		{
			temp = ft_lstnew(lst->content);
			if (temp == NULL)
			{
				write(1, "Error\n", 6);
				free_stack(v->stack);
				ft_lstclear(&v->a, dummy);
				ft_lstclear(&v->c, dummy);
				ft_lstclear(&v->d, dummy);
				exit(0);
			}
			ft_lstadd_back(&v->d, temp);
		}
		else if (i == end)
			return ;
		lst = lst->next;
	}
}
