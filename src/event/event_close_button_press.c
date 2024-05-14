#include "so_long.h"

int	event_close_button_press(t_game *game)
{
	game_destroy(game);
	exit(0);
	return(0);
}
