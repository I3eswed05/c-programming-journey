/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_idx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:00:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:34 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(t_list *a, int n)
{
	int	*i;
	int	idx;

	i = malloc(sizeof(int) * n);
	if (!i)
		return (NULL);
	idx = 0;
	while (a)
	{
		i[idx++] = a->value;
		a = a->next;
	}
	return (i);
}

void	sel_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_positions(t_list *a, int *arr, int n)
{
	int		i;
	t_list	*t;

	i = 0;
	t = a;
	while (t)
	{
		i = 0;
		while (i < n && arr[i] != t->value)
			i++;
		t->index = i;
		t = t->next;
	}
}

void	assign_indices(t_list *a)
{
	int		n;
	int		*arr;
	t_list	*t;

	n = 0;
	t = a;
	while (t)
	{
		n++;
		t = t->next;
	}
	if (n == 0)
		return ;
	arr = make_arr(a, n);
	if (!arr)
		return ;
	sel_sort(arr, n);
	assign_positions(a, arr, n);
	free(arr);
}
