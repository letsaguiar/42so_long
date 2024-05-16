#include "so_long.h"
#include <mlx.h>

int	event_render(t_game *game)
{
	mlx_put_image_to_window(game->app->mlx, game->app->win, coins_insert(game->coins)->img, 0, 0);
	return (0);
}
