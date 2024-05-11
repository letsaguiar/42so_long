#include "so_long.h"

int	event_key_release(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		game_destroy(game);
		exit(0);
	}
	return (0);
}
