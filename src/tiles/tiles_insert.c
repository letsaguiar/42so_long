#include "so_long.h"

void	tiles_insert(t_image *tiles, t_image *buffer, t_map *map)
{
	for (int x = 0; x < map_get_width(map); x++)
		for (int y = 0; y < map_get_height(map); y++)
			if (map_get_position(map, x, y)->value == '1')
				image_copy(buffer, tiles, x * GAME_BLOCK_SIZE, y * GAME_BLOCK_SIZE);
}
