#include "so_long.h"
#include <mlx.h>

t_image	*image_init(t_game *game, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof (t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(game->mlx, width, height);
	if (!image->img)
	{
		image_destroy(game, image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(
		image->img,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian
	);
	if (!image->addr)
	{
		image_destroy(game, image);
		return (NULL);
	}
	image->width = width;
	image->height = height;
	return (image);
}
