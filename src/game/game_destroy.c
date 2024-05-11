#include "so_long.h"

void	game_destroy(t_game *game)
{
	if (game->map)
		map_destroy(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
