/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:06:19 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:26:56 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first(t_list **s)
{
	t_list	*a;
	t_list	*b;

	if (!s || !*s || !(*s)->next)
		return ;
	a = *s;
	b = a->next;
	a->next = b->next;
	b->next = a;
	*s = b;
}

void	sa(t_list **a)
{
	swap_first(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap_first(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap_first(a);
	swap_first(b);
	write(1, "ss\n", 3);
}
