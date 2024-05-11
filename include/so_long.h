#ifndef SO_LONG_H
# define SO_LONG_H

/* Errors */
# define ARGUMENT_ERROR 1
# define MLX_ERROR 2

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

typedef struct s_map
{
	char			value;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_game;

t_map	*map_init(char value);

void	map_destroy(t_map *map);

void	map_append(t_map *map, t_map *append);

int		map_get_width(t_map *map);

int		map_get_height(t_map *map);

t_map	*map_get_position(t_map *map, int x, int y);

t_map	*map_parse_file(char *filename);

void	game_init(char *map_file);

void	game_destroy(t_game *game);

int		event_close_button_press(t_game *game);

int		event_key_release(int keycode, t_game *game);

#endif
