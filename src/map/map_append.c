#include "so_long.h"

void	map_append(t_map *map, t_map *append)
{
	if (map->next)
		return (map_append(map->next, append));
	map->next = append;
}
