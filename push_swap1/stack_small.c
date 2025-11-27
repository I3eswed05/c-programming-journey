/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:00:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:28:40 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *s)
{
	int	c;

	c = 0;
	while (s)
	{
		c++;
		s = s->next;
	}
	return (c);
}

int	is_sorted(t_list *s)
{
	while (s && s->next)
	{
		if (s->value > s->next->value)
			return (0);
		s = s->next;
	}
	return (1);
}

int	get_min_pos(t_list *s)
{
	int	p;
	int	mp;
	int	mv;

	if (!s)
		return (0);
	p = 0;
	mp = 0;
	mv = s->value;
	while (s)
	{
		if (s->value < mv)
		{
			mv = s->value;
			mp = p;
		}
		p++;
		s = s->next;
	}
	return (mp);
}

void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

int	build_stack(int ac, char **av, t_list **a)
{
	int	i;
	int	len;
	int	v;

	i = 1;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (!ft_check(av[i]) || len > 11 || !ft_overflow_check(av[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		v = ft_atoi(av[i]);
		if (!push_one(v, a))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
