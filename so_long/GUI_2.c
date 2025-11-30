/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:57 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 21:15:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_game *g, int x, int y)
{
	char	tile;

	tile = g->map[y][x];
	/* draw floor or wall base */
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor,
			x * TILE_SIZE, y * TILE_SIZE);
	/* draw coin if still present in map */
	if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.collect,
			x * TILE_SIZE, y * TILE_SIZE);
	/* draw player */
	if (g->player_x == x && g->player_y == y)
		mlx_put_image_to_window(g->mlx, g->win, g->img.player,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->rows)
	{
		x = 0;
		while (x < g->cols)
		{
			put_tile(g, x, y);
			x++;
		}
		y++;
	}
	/* draw exit only when all coins collected, using stored position */
	if (g->exit_x >= 0 && g->exit_y >= 0 && g->collected == g->total_c)
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit,
			g->exit_x * TILE_SIZE, g->exit_y * TILE_SIZE);
}
