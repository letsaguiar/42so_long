#include "so_long.h"

void	map_destroy(t_map *map)
{
	if (map->next)
		map_destroy(map->next);
	free(map);
}
