#include "so_long.h"

void	coins_insert(t_image **coins, t_image *buffer, t_map *map)
{
	static int	current;

	if (current > 7)
		current = 0;

	for (int x = 0; x < map_get_width(map); x++)
		for (int y = 0; y < map_get_height(map); y++)
			if (map_get_position(map, x, y)->value == 'C')
				image_copy(buffer, coins[current], x * GAME_BLOCK_SIZE, y * GAME_BLOCK_SIZE);

	current += 1;
}
