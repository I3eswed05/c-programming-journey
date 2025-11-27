/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:53:46 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:24 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_n(t_list **s, t_list **d)
{
	t_list	*t;

	if (!s || !*s)
		return ;
	t = *s;
	*s = t->next;
	t->next = *d;
	*d = t;
}

void	pa(t_list **a, t_list **b)
{
	push_n(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push_n(a, b);
	write(1, "pb\n", 3);
}
