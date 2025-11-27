/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:00:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:17:08 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_list *s)
{
	int	pos;
	int	max;
	int	mp;

	pos = 0;
	max = -1;
	mp = 0;
	while (s)
	{
		if (s->index > max)
		{
			max = s->index;
			mp = pos;
		}
		pos++;
		s = s->next;
	}
	return (mp);
}

void	bring_max_top(t_list **b, int pos)
{
	int	sz;
	int	cnt;

	sz = stack_size(*b);
	if (pos <= sz / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		cnt = sz - pos;
		while (cnt-- > 0)
			rrb(b);
	}
}

int	push_one_and_rotate(t_list **a, t_list **b, int limit, int chunk)
{
	pb(a, b);
	if (*b && (*b)->index <= limit - (chunk / 2))
		rb(b);
	return (1);
}

int	chunk_value(int n)
{
	if (n <= 100)
		return (20);
	return (45);
}
