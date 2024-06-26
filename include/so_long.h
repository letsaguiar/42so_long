#ifndef SO_LONG_H
# define SO_LONG_H

/* Errors */
# define ARGUMENT_ERROR 1
# define MLX_ERROR 2
# define GAME_ERROR 3

/* Game */
# ifndef GAME_BLOCK_SIZE
#  define GAME_BLOCK_SIZE 48
# endif

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

typedef struct s_app
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_app;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_game
{
	t_map	*map;
	t_app	*app;
	t_image	*background;
	t_image	*tiles;
	t_image	**coins;
}	t_game;

t_map	*map_init(char value);

void	map_destroy(t_map *map);

void	map_append(t_map *map, t_map *append);

int		map_get_width(t_map *map);

int		map_get_height(t_map *map);

t_map	*map_get_position(t_map *map, int x, int y);

t_map	*map_parse_file(char *filename);

t_app	*app_init(int width, int height, char *title);

void	app_destroy(t_app *app);

t_image	*image_init(t_app *app, int width, int height);

t_image	*image_init_from_xpm(t_app *app, char *filename);

void	image_destroy(t_app *app, t_image *image);

void	image_paint(t_image *image, int x, int y, int color);

void	image_copy(t_image *buffer, t_image *image, int x, int y);

t_image	*background_init(t_app *app);

void	background_destroy(t_app *app, t_image *background);

void	background_insert(t_image *background, t_image *buffer);

t_image	*tiles_init(t_app *app);

void	tiles_destroy(t_app *app, t_image *tiles);

void	tiles_insert(t_image *tiles, t_image *buffer, t_map *map);

t_image	**coins_init(t_app *app);

void	coins_destroy(t_app *app, t_image **coins);

void	coins_insert(t_image **coins, t_image *buffer, t_map *map);

t_game	*game_init(t_map *map, t_app *app, t_image *background, t_image *tiles, t_image **coins);

void	game_destroy(t_game *game);

void	game_run(t_game *game);

int		event_close_button_press(t_game *game);

int		event_key_release(int keycode, t_game *game);

int		event_render(t_game *game);

#endif
