/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+ +:+         +:+     */
/*   By: ialausud                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:20:00 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 21:30:00 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

static void	try_collect(t_game *g, int x, int y)
{
	if (g->map[y][x] == 'C')
	{
		g->map[y][x] = '0';
		g->collected++;
	}
}

void	move_player(t_game *g, int dx, int dy)
{
	int	nx;
	int	ny;
	char	next_tile;

	nx = g->player_x + dx;
	ny = g->player_y + dy;
	if (nx < 0 || ny < 0 || nx >= g->cols || ny >= g->rows)
		return ;
	next_tile = g->map[ny][nx];
	if (next_tile == '1')
		return ;
	try_collect(g, nx, ny);
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = nx;
	g->player_y = ny;
	g->map[ny][nx] = 'P';
	g->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(g->moves);
	write(1, "\n", 1);
	render_map(g);
	/* if we are on exit position and all coins collected -> win */
	if (g->exit_x >= 0 && g->exit_y >= 0
		&& g->player_x == g->exit_x && g->player_y == g->exit_y
		&& g->collected == g->total_c)
	{
		write(1, "You win!\n", 9);
		close_window(g);
	}
}

int	handle_key(int keycode, t_game *g)
{
	if (keycode == 65307)
		return (close_window(g), 0);
	if (keycode == 119 || keycode == 65362)
		move_player(g, 0, -1);
	else if (keycode == 115 || keycode == 65364)
		move_player(g, 0, 1);
	else if (keycode == 97 || keycode == 65361)
		move_player(g, -1, 0);
	else if (keycode == 100 || keycode == 65363)
		move_player(g, 1, 0);
	return (0);
}
