#include "so_long.h"

int	map_get_width(t_map *map)
{
	int	width;

	width = 0;
	while (map && map->value != '\n')
	{
		map = map->next;
		width++;
	}
	return (width);
}
