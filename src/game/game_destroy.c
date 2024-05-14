#include "so_long.h"

void	game_destroy(t_game *game)
{
	if (game->map)
		map_destroy(game->map);
	if (game->app)
		app_destroy(game->app);
	free(game);
}
