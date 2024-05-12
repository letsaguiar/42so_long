#include "so_long.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_map			*map;
	t_application	app;

	if (argc < 2 || !(map = map_parse_file(argv[1])))
	{
		ft_printf("Error: Invalid Argument");
		return (ARGUMENT_ERROR);
	}
	if (!(app_init(&app, map_get_width(map), map_get_height(map), "So Long")))
	{
		ft_printf("Error: Minilibx Error");
		return (MLX_ERROR);
	}
	game_init(&app);
}
