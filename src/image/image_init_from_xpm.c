#include "so_long.h"
#include <mlx.h>

t_image	*image_init_from_xpm(t_application *app, char *xpm_file)
{
	t_image	*image;

	image = malloc(sizeof (t_image));
	if (!image)
		return (NULL);
	image->img = mlx_xpm_file_to_image(
		app->mlx,
		xpm_file,
		&image->width,
		&image->height
	);
	if (!image->img)
	{
		image_destroy(app, image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(
		image->img,
		&image->bits_per_pixel,
		&image->line_length,
		&image->endian
	);
	return (image);
}
