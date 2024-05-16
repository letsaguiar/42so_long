#include "so_long.h"
#include <mlx.h>

int	event_render(t_game *game)
{
	t_image	*buffer;

	buffer = image_init(game->app, game->app->width, game->app->height);
	if (!buffer)
	{
		game_destroy(game);
		exit(0);
	}

	background_insert(game->background, buffer);
	tiles_insert(game->tiles, buffer, game->map);
	coins_insert(game->coins, buffer, game->map);

	mlx_put_image_to_window(game->app->mlx, game->app->win, buffer->img, 0, 0);
	image_destroy(game->app, buffer);

	return (0);
}
