#include "so_long.h"

t_map	*map_get_position(t_map *map, int x, int y)
{
	int	i, j;

	i = 0;
	while (map && i < y)
	{
		if (map->value == '\n')
			i++;
		map = map->next;
	}
	j = 0;
	while (map && map->value != '\n' && j < x)
	{
		map = map->next;
		j++;
	}
	if (!map || map->value == '\n')
		return (NULL);
	return (map);
}
