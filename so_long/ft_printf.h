#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		total_c;
	int		collected;
	int		moves;
	void	*mlx;
	void	*win;
	t_img	img;
}	t_game;

/* libft / gnl */
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

/* map / validation */
int		is_ber(char *map);
char	**read_map(int fd);
int		is_rectangle(char **map);
int		validation(char **map);
int		count_components(char **map);
int		count_help(char ch, int *c, int *e, int *p);
int		check_paths(char **map);
char	**copy_map(char **map);
void	free_map(char **map);

/* game / GUI */
void	init_game(t_game *g, char **map);
int		load_images(t_game *g);
void	render_map(t_game *g);

/* controls */
int		handle_key(int keycode, t_game *g);
int		close_window(t_game *g);

/* move / collectibles */
void	move_player(t_game *g, int dx, int dy);

#endif
