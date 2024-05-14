#include "so_long.h"

static char	*get_offset(t_image *image, int x, int y)
{
	return (image->addr + (y * image->line_length) + (x * image->bits_per_pixel / 8));
}

static unsigned int	get_color(t_image *image, int x, int y)
{
	return *(unsigned int *) get_offset(image, x, y);
}

void	image_copy(t_image *buffer, t_image *image, int x, int y)
{
	for (int i = 0; i < image->width; i++)
		for (int j = 0; j < image->width; j++)
			if (get_color(image, i, j) != 0xFF000000)
				image_paint(buffer, x + i, y + j, get_color(image, i, j));
}
