#ifndef SO_LONG_H
# define SO_LONG_H

/* Errors */
# define ARGUMENT_ERROR 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	char			value;
	struct s_map	*next;
}	t_map;

t_map	*map_init(char value);

void	map_destroy(t_map *map);

void	map_append(t_map *map, t_map *append);

int		map_get_width(t_map *map);

int		map_get_height(t_map *map);

t_map	*map_get_position(t_map *map, int x, int y);

t_map	*map_parse_file(char *filename);

#endif
