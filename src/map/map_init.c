#include "so_long.h"

t_map	*map_init(char value)
{
	t_map	*map;

	map = malloc(sizeof (t_map));
	if (!map)
		return (NULL);
	map->value = value;
	map->next = NULL;
	return (map);
}
