/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUI_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <ialausud@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:13:38 by ialausud          #+#    #+#             */
/*   Updated: 2025/11/30 20:44:37 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g, char **map)
{
    int	i;
    int	j;

    g->map = map;
    g->rows = 0;
    while (map[g->rows])
        g->rows++;
    g->cols = ft_strlen(map[0]);
    g->total_c = 0;
    g->collected = 0;
    g->moves = 0;
    g->player_x = 0;
    g->player_y = 0;
    g->exit_x = -1;
    g->exit_y = -1;
    /* ensure image handles start NULL so cleanup is safe on failure */
    g->img.wall = NULL;
    g->img.floor = NULL;
    g->img.player = NULL;
    g->img.collect = NULL;
    g->img.exit = NULL;
    i = 0;
    while (i < g->rows)
    {
        j = 0;
        while (j < g->cols)
        {
            if (map[i][j] == 'P')
            {
                g->player_x = j;
                g->player_y = i;
            }
            else if (map[i][j] == 'C')
                g->total_c++;
            else if (map[i][j] == 'E')
            {
                g->exit_x = j;
                g->exit_y = i;
                g->map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}


int	load_images(t_game *g)
{
    int	w;
    int	h;

    w = TILE_SIZE;
    h = TILE_SIZE;
    g->img.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
    g->img.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
    g->img.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &w, &h);
    g->img.collect = mlx_xpm_file_to_image(g->mlx, "textures/coin.xpm", &w, &h);
    g->img.exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
    if (!g->img.wall || !g->img.floor || !g->img.player
        || !g->img.collect || !g->img.exit)
    {
        /* destroy any images that did load */
        if (g->img.player)
            mlx_destroy_image(g->mlx, g->img.player);
        if (g->img.collect)
            mlx_destroy_image(g->mlx, g->img.collect);
        if (g->img.exit)
            mlx_destroy_image(g->mlx, g->img.exit);
        if (g->img.wall)
            mlx_destroy_image(g->mlx, g->img.wall);
        if (g->img.floor)
            mlx_destroy_image(g->mlx, g->img.floor);
        /* if using minilibx-linux, destroy display and free mlx handle */
        if (g->mlx)
        {
            mlx_destroy_display(g->mlx);
            free(g->mlx);
            g->mlx = NULL;
        }
        /* reset pointers to avoid double-free later */
        g->img.wall = g->img.floor = g->img.player = NULL;
        g->img.collect = g->img.exit = NULL;
        return (0);
    }
    return (1);
}

/* destroy images if loaded */
static void	destroy_images(t_game *g)
{
    if (!g || !g->mlx)
        return ;
    if (g->img.player)
        mlx_destroy_image(g->mlx, g->img.player);
    if (g->img.collect)
        mlx_destroy_image(g->mlx, g->img.collect);
    if (g->img.exit)
        mlx_destroy_image(g->mlx, g->img.exit);
    if (g->img.wall)
        mlx_destroy_image(g->mlx, g->img.wall);
    if (g->img.floor)
        mlx_destroy_image(g->mlx, g->img.floor);
}

/* cleanup and exit safely; matches header signature */
int	close_window(t_game *g)
{
    if (!g)
        exit(0);
    /* destroy images and window */
    destroy_images(g);
    if (g->win)
        mlx_destroy_window(g->mlx, g->win);
    /* destroy display and free mlx handle for minilibx-linux */
    if (g->mlx)
    {
        mlx_destroy_display(g->mlx);
        free(g->mlx);
    }
    /* free map and exit */
    free_map(g->map);
    exit(0);
    return (0);
}
