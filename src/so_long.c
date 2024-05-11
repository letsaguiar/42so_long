#include "so_long.h"
#include "libft.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error: Invalid Argument");
		return (ARGUMENT_ERROR);
	}
	game_init(argv[1]);
}
