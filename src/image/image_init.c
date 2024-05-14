#include "so_long.h"
#include "libft.h"

t_image	*image_init(t_app *app, int width, int height)
{
	t_image	*image;

	image = ft_calloc(1, sizeof (t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(app->mlx, width, height);
	if (!image)
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
	if (!image->addr)
	{
		image_destroy(app, image);
		return (NULL);
	}
	image->width = width;
	image->height = height;
	return (image);
}
