#include "so_long.h"

t_map	*map_parse_file(char *filename)
{
	int		fd;
	char	buffer;
	t_map	*map;
	t_map	*append;

	fd = open(filename, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
	{
		if (!map)
		{
			if (!(map = map_init(buffer)))
				return (NULL);
		}
		else
		{
			if (!(append = map_init(buffer)))
			{
				map_destroy(map);
				return (NULL);
			}
			map_append(map, append);
		}
	}
	return (map);
}
