#include "so_long.h"
#include "libft.h"

int main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2 || !(map = map_parse_file(argv[1])))
	{
		ft_printf("Error: Invalid Argument");
		return (ARGUMENT_ERROR);
	}
	return (0);
}
