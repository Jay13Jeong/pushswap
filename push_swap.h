#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_v
{
	int			cnt;
	int			piece;
	int			part;
	int			part_curr;
	int			border;
	int			std;
	int			ssize;
	int			target;
	int			move;
	int			rrr;
	int			rrr2;
	int			s_d;
	int			b_d;
	char		**stack;
	t_list		*a;
	t_list		*b;
	t_list		*c;
	t_list		*d;
}				t_v;

void	sa(t_list *lst);
void	pushpop(t_list **a, t_list **b);
void	rev_rotation(t_list **lst);
void	rotation(t_list **lst);
void	rrr(t_v *v);
void	order(char *str, t_v *v);
int		free_stack(char **arr);
void	sort(char **stack, int size);
void	dummy(void *contnent);
void	check_ab(t_v *v);
int		lstmax(t_list *lst);
int		lstmin(t_list *lst);
int		check_lst(t_list *lst);
int		check_lst_rev(t_list *lst);
void	inserta(t_v *v);
int		check_abottom(t_v *v);
void	rtna(t_v *v);
void	rtnb(int target, t_v *v);
void	init_ab(t_v *v);
void	init_c(t_v *v);
void	init_d(t_v *v, int start, int end, t_list *lst);
int		lst_idx(t_list *lst, int idx);
int		lst_location(t_list *lst, int data);
void	pop(t_list **lst, int data);
void	push_swap(t_v *v);
void	print_error(void *e);
int		check_space(char c);
int		check_overflow(char *str);
int		condition_check(char **stack1, char **stack2);
char	**make_stack(char *abc, int *size);
char	*join_all(int argc, char **argv, char *abc);
void	init_struct(t_v *v);
int		sort3data(t_v *v);
void	select_sort(t_v *v);
int		process_last_part(t_v *v);
void	find_parts(t_v *v);
void	make_parts_to_b(t_v *v);
void	parts_idx_cmp(t_v *v);
void	part_sort_and_pa(t_v *v);
void	assemble_parts(t_v *v);

#endif
