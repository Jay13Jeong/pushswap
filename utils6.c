#include "push_swap.h"

int	check_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\r' || c == '\f' || c == '\v');
}

int	check_overflow(char *str)
{
	int			minus;
	int			total;

	minus = 1;
	while (check_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			minus *= -1;
	total = 0;
	while (ft_isdigit(*str))
	{
		total *= 10;
		total += (*(str++) - '0') * minus;
		if (minus < 0 && total > 0)
			return (0);
		else if (minus > 0 && total < 0)
			return (0);
	}
	return (1);
}

int	condition_check(char **stack1, char **stack2)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (stack1[i])
	{
		if (!check_overflow(stack1[i]))
			return (free_stack(stack1));
		temp = ft_atoi(stack1[i]);
		j = -1;
		while (stack2[++j])
		{
			if (i == j)
				continue ;
			if (temp == ft_atoi(stack2[j]))
				return (free_stack(stack1));
		}
		i++;
	}
	return (1);
}

char	**make_stack(char *abc, int *size)
{
	int		i;
	int		j;
	char	**stack;

	stack = ft_split(abc, ' ');
	free(abc);
	if (stack == NULL)
		return (0);
	if (*stack == NULL)
		return ((char **)(size_t)free_stack(stack));
	i = -1;
	while (stack[++i])
	{
		j = 0;
		if (!ft_isdigit(stack[i][j]))
			if (stack[i][j] != '+' && stack[i][j] != '-')
				return ((char **)(size_t)free_stack(stack));
		while (stack[i][++j])
			if (!ft_isdigit(stack[i][j]))
				return ((char **)(size_t)free_stack(stack));
	}
	*size = i;
	return (stack);
}

char	*join_all(int argc, char **argv, char *abc)
{
	int		i;
	char	*temp;

	i = 0;
	while (++i < argc)
	{
		temp = ft_strjoin(abc, argv[i]);
		free(abc);
		if (temp == NULL)
			return (0);
		abc = temp;
		temp = ft_strjoin(abc, " ");
		free(abc);
		if (temp == NULL)
			return (0);
		abc = temp;
	}
	return (abc);
}
