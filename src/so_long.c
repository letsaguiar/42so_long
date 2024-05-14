#include "so_long.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_map	*map;
	t_app	*app;
	t_game	*game;

	if (argc < 2 || !(map = map_parse_file(argv[1])))
	{
		ft_printf("Error: Invalid Argument");
		return (ARGUMENT_ERROR);
	}
	if (!(app = app_init(map_get_width(map), map_get_height(map), "So Long")))
	{
		ft_printf("Error: Invalid Argument");
		return (MLX_ERROR);
	}
	if (!(game = game_init(map, app)))
	{
		ft_printf("Error: Game Error");
		return (GAME_ERROR);
	}

	game_run(game);
}
