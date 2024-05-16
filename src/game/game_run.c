#include "so_long.h"

void	game_run(t_game *game)
{
	mlx_hook(game->app->win, DestroyNotify, StructureNotifyMask, event_close_button_press, game);
	mlx_hook(game->app->win, KeyRelease, KeyReleaseMask, event_key_release, game);
	mlx_loop_hook(game->app->mlx, event_render, game);
	mlx_loop(game->app->mlx);
}
