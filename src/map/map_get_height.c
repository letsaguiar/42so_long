#include "so_long.h"

int	map_get_height(t_map *map)
{
	int	height;

	height = 0;
	while (map)
	{
		if (map->value == '\n')
			height++;
		map = map->next;
	}
	return (height);
}
