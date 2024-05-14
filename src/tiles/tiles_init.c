#include "so_long.h"

t_image	*tiles_init(t_app *app, t_map *map)
{
	t_image	*sand;
	t_image	*tiles;

	sand = image_init_from_xpm(app, "assets/tiles/land.xpm");
	if (!sand)
		return (NULL);
	tiles = image_init(app, app->width, app->height);
	if (!tiles)
	{
		image_destroy(app, sand);
		return (NULL);
	}

	for (int x = 0; x < map_get_width(map); x++)
		for (int y = 0; y < map_get_height(map); y++)
			if (map_get_position(map, x, y)->value == '1')
				image_copy(tiles, sand, x * GAME_BLOCK_SIZE, y * GAME_BLOCK_SIZE);

	image_destroy(app, sand);
	return (tiles);
}
