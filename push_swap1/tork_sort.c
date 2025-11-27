/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tork_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:00:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:04:26 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tork_push_phase(t_list **a, t_list **b)
{
	int	n;
	int	chunk;
	int	pushed;
	int	limit;

	if (!a || !*a)
		return ;
	assign_indices(*a);
	n = stack_size(*a);
	chunk = chunk_value(n);
	pushed = 0;
	limit = chunk - 1;
	while (stack_size(*a) > 0)
	{
		if ((*a)->index <= limit)
		{
			pushed += push_one_and_rotate(a, b, limit, chunk);
			if (pushed > limit)
				limit += chunk;
		}
		else
			ra(a);
	}
}

void	tork_pull_phase(t_list **a, t_list **b)
{
	int	pos;

	while (*b)
	{
		pos = get_max_pos(*b);
		bring_max_top(b, pos);
		pa(a, b);
	}
}

void	tork_sort(t_list **a, t_list **b)
{
	tork_push_phase(a, b);
	tork_pull_phase(a, b);
}
