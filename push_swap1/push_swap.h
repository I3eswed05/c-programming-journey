/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:35:26 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:05:59 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_list;

t_list				*ft_lstnew(int value);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
int					ft_check_duplicates(t_list *stack, int value);

size_t				ft_strlen(const char *str);
int					ft_check(const char *str);
int					ft_overflow_check(const char *str);
int					ft_atoi(const char *str);
int					push_one(int v, t_list **a);

int					stack_size(t_list *stack);
int					is_sorted(t_list *stack);
int					get_min_pos(t_list *s);
void				sort_three(t_list **a);

void				sort_small(t_list **a, t_list **b);
void				rotate_up_n(t_list **a, int n);
void				rotate_down_n(t_list **a, int n);
void				push_mins(t_list **a, t_list **b);

int					*make_arr(t_list *a, int n);
void				sel_sort(int *arr, int n);
void				assign_positions(t_list *a, int *arr, int n);
void				assign_indices(t_list *a);

int					get_max_pos(t_list *s);
void				bring_max_top(t_list **b, int pos);
int					push_one_and_rotate(t_list **a, t_list **b, int limit,
						int chunk);
int					chunk_value(int n);
void				tork_sort(t_list **a, t_list **b);
void				tork_push_phase(t_list **a, t_list **b);
void				tork_pull_phase(t_list **a, t_list **b);

void				swap_first(t_list **s);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

void				push_n(t_list **s, t_list **d);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);

void				rot_one(t_list **s);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

void				rrot_one(t_list **s);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

int					build_stack(int argc, char **argv, t_list **a);

#endif
