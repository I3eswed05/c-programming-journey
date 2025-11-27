/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:00:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:01:39 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_n(t_list **a, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		ra(a);
}

void	rotate_down_n(t_list **a, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		rra(a);
}

void	push_mins(t_list **a, t_list **b)
{
	int	p;
	int	sz;

	while (stack_size(*a) > 3)
	{
		p = get_min_pos(*a);
		sz = stack_size(*a);
		if (p <= sz / 2)
			rotate_up_n(a, p);
		else
			rotate_down_n(a, sz - p);
		pb(a, b);
	}
}

void	sort_small(t_list **a, t_list **b)
{
	int	sz;

	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	sz = stack_size(*a);
	if (sz == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (sz == 3)
	{
		sort_three(a);
		return ;
	}
	push_mins(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
