/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:01:45 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:06:54 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check(const char *s)
{
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s && (*s >= '0' && *s <= '9'))
		s++;
	return (*s == '\0');
}

int	ft_atoi(const char *s)
{
	long	r;
	int		sign;

	r = 0L;
	sign = 1;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		r = r * 10 + (*s - '0');
		s++;
	}
	return ((int)(r * sign));
}

int	ft_overflow_check(const char *s)
{
	long	r;
	int		sign;

	r = 0L;
	sign = 1;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		r = r * 10 + (*s - '0');
		s++;
	}
	r *= sign;
	return (r <= 2147483647 && r >= -2147483648);
}

int	push_one(int v, t_list **a)
{
	t_list	*n;

	if (*a && !ft_check_duplicates(*a, v))
		return (0);
	n = ft_lstnew(v);
	if (!n)
		return (0);
	ft_lstadd_back(a, n);
	return (1);
}
