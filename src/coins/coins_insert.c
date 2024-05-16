#include "so_long.h"

t_image	*coins_insert(t_image **coins)
{
	static int	current;

	if (current > 7)
		current = 0;
	current += 1;
	return (coins[current - 1]);
}
