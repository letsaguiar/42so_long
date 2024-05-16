#include "so_long.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_map	*map;
	t_app	*app;
	t_image	*background;
	t_image	*tiles;
	t_image	**coins;
	t_game	*game;

	if (argc < 2 || !(map = map_parse_file(argv[1])))
	{
		ft_printf("Error: Invalid Argument");
		return (ARGUMENT_ERROR);
	}
	if (
		!(app = app_init(map_get_width(map) * GAME_BLOCK_SIZE, map_get_height(map) * GAME_BLOCK_SIZE, "So Long"))
		|| !(background = background_init(app))
		|| !(tiles = tiles_init(app, map))
		|| !(coins = coins_init(app))
	)
	{
		ft_printf("Error: ");
		return (MLX_ERROR);
	}
	if (!(game = game_init(map, app, background, tiles, coins)))
	{
		ft_printf("Error: Game Error");
		return (GAME_ERROR);
	}

	game_run(game);
}
