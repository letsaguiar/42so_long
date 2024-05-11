#include "so_long.h"
#include "libft.h"

static void	game_init_map(t_game *game, char *map_file)
{
	if (!(game->map = map_parse_file(map_file)))
	{
		ft_printf("Error: Invalid Argument");
		exit(ARGUMENT_ERROR);
	}
}

static void	game_init_mlx(t_game *game)
{
	if (!(game->mlx = mlx_init()))
	{
		game_destroy(game);
		ft_printf("Error: Minilibx Error");
		exit(MLX_ERROR);
	}
}

static void	game_init_window(t_game *game)
{
	game->win = mlx_new_window(
		game->mlx,
		map_get_width(game->map) * 48,
		map_get_height(game->map) * 48,
		"So Long"
	);
	if (!game->win)
	{
		game_destroy(game);
		ft_printf("Error: Minilibx Error");
		exit(MLX_ERROR);
	}
}

static void	game_init_hooks(t_game *game)
{
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, event_close_button_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, event_key_release, game);
}

void	game_init(char *map_file)
{
	t_game	game;

	game_init_map(&game, map_file);
	game_init_mlx(&game);
	game_init_window(&game);
	game_init_hooks(&game);

	mlx_loop(game.mlx);
}
