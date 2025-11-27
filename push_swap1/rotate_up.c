/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:08:52 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:08 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_one(t_list **s)
{
	t_list	*f;
	t_list	*l;

	if (!s || !*s || !(*s)->next)
		return ;
	f = *s;
	*s = f->next;
	f->next = NULL;
	l = *s;
	while (l->next)
		l = l->next;
	l->next = f;
}

void	ra(t_list **a)
{
	rot_one(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rot_one(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rot_one(a);
	rot_one(b);
	write(1, "rr\n", 3);
}
