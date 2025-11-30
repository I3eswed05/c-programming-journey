/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*   By: ialausud                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:24:33 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 21:00:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_player(char **map, int *px, int *py)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*px = i;
				*py = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	flood_fill(char **map, int x, int y, int rows, int cols)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, rows, cols);
	flood_fill(map, x - 1, y, rows, cols);
	flood_fill(map, x, y + 1, rows, cols);
	flood_fill(map, x, y - 1, rows, cols);
}

static int	get_rows(char **map)
{
	int	r;

	r = 0;
	while (map[r])
		r++;
	return (r);
}

static int	get_cols(char **map)
{
	if (!map || !map[0])
		return (0);
	return (ft_strlen(map[0]));
}

int	check_paths(char **map)
{
	char	**tmp;
	int		rows;
	int		cols;
	int		px;
	int		py;
	int		i;
	int		j;

	tmp = copy_map(map);
	if (!tmp)
		return (0);
	rows = get_rows(tmp);
	cols = get_cols(tmp);
	if (!find_player(tmp, &px, &py))
		return (free_map(tmp), 0);
	flood_fill(tmp, px, py, rows, cols);
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == 'C' || tmp[i][j] == 'E')
				return (free_map(tmp), 0);
			j++;
		}
		i++;
	}
	free_map(tmp);
	return (1);
}
