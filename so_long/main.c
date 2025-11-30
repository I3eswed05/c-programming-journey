#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int		fd;
	t_game	game;

	if (ac != 2 || !is_ber(av[1]))
		return (write(2, "Error\nInvalid map\n", 18), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\ncould not open map\n", 25), 1);
	map = read_map(fd);
	close(fd);
	if (!map)
		return (write(2, "Error\ninvalid map\n", 18), 1);
	if (!validation(map))
		return (write(2, "Error\ninvalid map\n", 18), free_map(map), 1);
	init_game(&game, map);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (free_map(map), 1);
	if (!load_images(&game))
		return (write(2, "Error\nimage load failed\n", 24),
			free_map(map), 1);
	game.win = mlx_new_window(game.mlx,
			game.cols * TILE_SIZE, game.rows * TILE_SIZE, "so_long");
	if (!game.win)
		return (free_map(map), 1);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
