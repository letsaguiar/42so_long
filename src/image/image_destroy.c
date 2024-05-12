#include "so_long.h"

void	image_destroy(t_application *app, t_image *image)
{
	if (image->img)
		mlx_destroy_image(app->mlx, image->img);
	free(image);
}
