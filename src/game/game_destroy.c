#include "so_long.h"

void	game_destroy(t_game *game)
{
	if (game->map)
		map_destroy(game->map);
	if (game->background)
		background_destroy(game->app, game->background);
	if (game->tiles)
		tiles_destroy(game->app, game->tiles);
	if (game->app)
		app_destroy(game->app);
	free(game);
}
