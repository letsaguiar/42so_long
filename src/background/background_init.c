#include "so_long.h"

t_image	*background_init(t_app *app)
{
	t_image	*background;

	background = image_init(app, app->width, app->height);
	if (!background)
		return (NULL);
	for (int x = 0; x < app->width; x++)
		for (int y = 0; y < app->height; y++)
			image_paint(background, x, y, 0x009BD4C3);
	return (background);
}
