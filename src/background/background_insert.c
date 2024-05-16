#include "so_long.h"

void	background_insert(t_image *background, t_image *buffer)
{
	image_copy(buffer, background, 0, 0);
}
