/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:10:22 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:31 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int v)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->value = v;
	n->index = 0;
	n->next = NULL;
	return (n);
}

t_list	*ft_lstlast(t_list *l)
{
	t_list	*p;

	if (!l)
		return (NULL);
	p = l;
	while (p->next)
		p = p->next;
	return (p);
}

void	ft_lstadd_back(t_list **l, t_list *n)
{
	t_list	*p;

	if (!l || !n)
		return ;
	if (!*l)
		*l = n;
	else
	{
		p = ft_lstlast(*l);
		p->next = n;
	}
}

void	ft_lstclear(t_list **l)
{
	t_list	*t;

	if (!l || !*l)
		return ;
	while (*l)
	{
		t = (*l)->next;
		free(*l);
		*l = t;
	}
	*l = NULL;
}

int	ft_check_duplicates(t_list *s, int v)
{
	t_list	*t;

	if (!s)
		return (1);
	t = s;
	while (t)
	{
		if (t->value == v)
			return (0);
		t = t->next;
	}
	return (1);
}
