/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:07:01 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:28:58 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrot_one(t_list **s)
{
	t_list	*p;
	t_list	*c;

	if (!s || !*s || !(*s)->next)
		return ;
	p = NULL;
	c = *s;
	while (c->next)
	{
		p = c;
		c = c->next;
	}
	p->next = NULL;
	c->next = *s;
	*s = c;
}

void	rra(t_list **a)
{
	rrot_one(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rrot_one(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrot_one(a);
	rrot_one(b);
	write(1, "rrr\n", 4);
}
