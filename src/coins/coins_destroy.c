#include "so_long.h"

void	coins_destroy(t_app *app, t_image **coins)
{
	for (int i = 0; i < 8; i++)
		if (coins[i])
			image_destroy(app, coins[i]);
	free(coins);
}
