#include "so_long.h"
#include "libft.h"

t_game	*game_init(t_map *map, t_app *app, t_image *background)
{
	t_game	*game;

	game = ft_calloc(1, sizeof (t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->app = app;
	game->background = background;
	return (game);
}
