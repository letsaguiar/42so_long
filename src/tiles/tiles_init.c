#include "so_long.h"

t_image	*tiles_init(t_app *app)
{
	return (image_init_from_xpm(app, "assets/tiles/land.xpm"));
}
