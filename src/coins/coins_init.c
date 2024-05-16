#include "so_long.h"
#include "libft.h"

t_image	**coins_init(t_app *app)
{
	t_image	**coins;

	coins = ft_calloc(8, sizeof (t_image *));
	if (!coins)
		return (NULL);

	coins[0] = image_init_from_xpm(app, "assets/coins/1.xpm");
	coins[1] = image_init_from_xpm(app, "assets/coins/2.xpm");
	coins[2] = image_init_from_xpm(app, "assets/coins/3.xpm");
	coins[3] = image_init_from_xpm(app, "assets/coins/4.xpm");
	coins[4] = image_init_from_xpm(app, "assets/coins/5.xpm");
	coins[5] = image_init_from_xpm(app, "assets/coins/6.xpm");
	coins[6] = image_init_from_xpm(app, "assets/coins/7.xpm");
	coins[7] = image_init_from_xpm(app, "assets/coins/8.xpm");

	for (int i = 0; i < 8; i++)
		if (!coins[i])
		{
			coins_destroy(app, coins);
			break;
		}

	return (coins);
}
