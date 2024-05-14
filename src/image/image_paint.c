#include "so_long.h"

static char	*get_offset(t_image *image, int x, int y)
{
	return (image->addr + (y * image->line_length) + (x * image->bits_per_pixel / 8));
}

void	image_paint(t_image *image, int x, int y, int color)
{
	((unsigned int *) get_offset(image, x, y))[0] = color;
}
