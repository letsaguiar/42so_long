#include "libft.h"
#include "so_long.h"

// static void	game_init_map(t_game *game, char *map_file)
// {
// 	if (!(game->map = map_parse_file(map_file)))
// 	{
// 		ft_printf("Error: Invalid Argument");
// 		exit(ARGUMENT_ERROR);
// 	}
// }

// static void	game_init_mlx(t_game *game)
// {
// 	if (!(game->mlx = mlx_init()))
// 	{
// 		game_destroy(game);
// 		ft_printf("Error: Minilibx Error");
// 		exit(MLX_ERROR);
// 	}
// }

// static void	game_init_window(t_game *game)
// {
// 	game->win = mlx_new_window(
// 		game->mlx,
// 		map_get_width(game->map) * 48,
// 		map_get_height(game->map) * 48,
// 		"So Long"
// 	);
// 	if (!game->win)
// 	{
// 		game_destroy(game);
// 		ft_printf("Error: Minilibx Error");
// 		exit(MLX_ERROR);
// 	}
// }

// static void	game_init_background(t_game *game)
// {
// 	game->background = image_init(
// 		game,
// 		map_get_width(game->map) * 48,
// 		map_get_height(game->map) * 48
// 	);
// 	if (!game->background)
// 	{
// 		game_destroy(game);
// 		ft_printf("Error: Minilibx Error");
// 		exit(MLX_ERROR);
// 	}

// 	for (int x = 0; x < game->background->width; x++)
// 		for (int y = 0; y < game->background->height; y++)
// 			image_paint(game->background, x, y, 0x009BC4D3);

// 	for (int i = 0; i < 50; i++)
// 	{
// 		int rs = (rand() % 31) + 20;
// 		int rx = rand() % (game->background->width - rs);
// 		int ry = rand() % (game->background->height - 10);

// 		for (int x = rx; x < rx + rs; x++)
// 			for (int y = ry; y < ry + 10; y++)
// 				image_paint(game->background, x, y, 0x00B1E0BE);

// 	}
// }

// static void	game_init_tile(t_game *game)
// {
// 	game->tile = image_init_from_xpm(game, "assets/tile.xpm");
// 	if (!game->tile)
// 	{
// 		game_destroy(game);
// 		ft_printf("Error: Minilibx Error");
// 		exit(MLX_ERROR);
// 	}
// }

// static void	game_init_hooks(t_game *game)
// {
// 	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, event_close_button_press, game);
// 	mlx_hook(game->win, KeyRelease, KeyReleaseMask, event_key_release, game);
// 	mlx_loop_hook(game->mlx, event_frame_render, game);
// }

t_game	*game_init(t_application *app, t_map *map)
{
	t_game	*game;

	game = ft_calloc(1, sizeof (t_game));
	if (!game)
		return (NULL);
	game->app = app;
	game->map = map;
	return (game);
}
