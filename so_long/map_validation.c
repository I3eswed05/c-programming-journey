/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:14:01 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 21:00:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(char **map)
{
	int	len;
	int	i;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	count_help(char ch, int *c, int *e, int *p)
{
	if (ch == 'P')
	{
		(*p)++;
		return (1);
	}
	if (ch == 'C')
	{
		(*c)++;
		return (1);
	}
	if (ch == 'E')
	{
		(*e)++;
		return (1);
	}
	if (ch == '1' || ch == '0')
		return (1);
	return (0);
}

static int	valid_borders(char **map)
{
	int	lines;
	int	width;
	int	i;
	int	j;

	lines = 0;
	while (map[lines])
		lines++;
	width = ft_strlen(map[0]);
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == lines - 1) && map[i][j] != '1')
				return (0);
			if ((j == 0 || j == width - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	count_components(char **map)
{
	int	c;
	int	e;
	int	p;
	int	i;
	int	j;

	c = 0;
	e = 0;
	p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!count_help(map[i][j], &c, &e, &p))
				return (0);
			j++;
		}
		i++;
	}
	if (!valid_borders(map))
		return (0);
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

char	**copy_map(char **map)
{
	int		count;
	char	**new_map;
	int		i;

	if (!map)
		return (NULL);
	count = 0;
	while (map[count])
		count++;
	new_map = malloc(sizeof(char *) * (count + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	validation(char **map)
{
	if (!map)
		return (0);
	if (!is_rectangle(map))
		return (0);
	if (!count_components(map))
		return (0);
	if (!check_paths(map))
	{
		write(1, "Error\ninvalid paths\n", 20);
		return (0);
	}
	return (1);
}
