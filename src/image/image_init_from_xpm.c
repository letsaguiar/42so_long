#include "so_long.h"
#include "libft.h"

t_image	*image_init_from_xpm(t_app *app, char *filename)
{
	t_image	*image;

	image = ft_calloc(1, sizeof (t_image));
	if (!image)
		return (NULL);
	image->img = mlx_xpm_file_to_image(app->mlx, filename, &image->width, &image->height);
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
	if (!image->addr)
	{
		image_destroy(app, image);
		return (NULL);
	}
	return (image);
}
