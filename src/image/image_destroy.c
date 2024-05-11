#include "so_long.h"

void	image_destroy(t_game *game, t_image *image)
{
	if (image->img)
		mlx_destroy_image(game->mlx, image->img);
	free(image);
}
