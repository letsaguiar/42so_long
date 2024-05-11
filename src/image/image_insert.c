#include "so_long.h"

static char	*get_offset(t_image *image, int x, int y)
{
	return (image->addr + (y * image->line_length) + (x * image->bits_per_pixel / 8));
}

void	image_insert(t_image *image, t_image *insert, int x, int y)
{
	for (int i = 0; i < insert->width; i++)
		for (int j = 0; j < insert->height; j++)
			*(unsigned int *) get_offset(image, x + i, y + j) = *(unsigned int *) get_offset(insert, i, j);
}
