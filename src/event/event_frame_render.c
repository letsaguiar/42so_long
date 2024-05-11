#include "so_long.h"

int	event_frame_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->background->img, 0, 0);
	return (0);
}
