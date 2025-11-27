/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:43:15 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/19 18:27:27 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
		if (!build_stack(ac, av, &a))
			return (1);
	if (a && stack_size(a) <= 5)
		sort_small(&a, &b);
	else if (a && !(is_sorted(a)))
		tork_sort(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
